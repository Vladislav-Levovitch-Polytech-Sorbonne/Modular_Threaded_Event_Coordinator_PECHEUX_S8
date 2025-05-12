 ![Bannière](./Useful_Resources/Images_ReadME/banner.png)
 # Modular_Threaded_Event_Coordinator_PECHEUX_S8
 # 📜 Technical Report - Networked Reactive System with FSM Control

## Introduction

This project explores the implementation of a distributed architecture using **low-level system** tools. While based on the game logic of *Sherlock 13*, its primary aim is not to reproduce game mechanics, but to **demonstrate and validate core system-level concepts**. Through the development of a networked server-client structure, we put into practice notions such as **sockets**, **multi-threading**, **mutex synchronization**, and **finite-state machines (FSMs)**.

The game setting serves as a *pedagogical vehicle* : it provides context for structured interactions that trigger transitions, **thread activities**, and message **broadcasts**. The server reacts according to an internal FSM, and the system ensures synchronization through mutex-protected shared resources, enabling us to study concurrency and communication under real-world constraints.

---

## System Architecture Overview

The system is composed of a **central server** and **four clients** connected over TCP. The server maintains a **FSM** that controls its behavior during the connection phase and throughout interaction cycles. Each client communicates with the server via a socket, sending structured messages and receiving game state updates in return.

The server uses multiple **POSIX threads** to handle each client independently, ensuring responsiveness and isolation of blocking I/O operations. A **mutex lock** protects shared resources such as the list of connected clients or the current state of the FSM.

---

## General Communication Architecture

### ![Figure 1 - General Communication Architecture](./Useful_Resources/Images_ReadME/figure1_comm_architecture.jpg)

This diagram illustrates the core structure of communication between components. At the center is the **main server**, responsible for maintaining the FSM and dispatching state updates. Four clients - Alice, Bob, Charlie, and Donald - connect to the server. Each client is associated with a **local mini-server**, a passive listener designed to handle incoming messages from the server asynchronously.

The green dotted arrows symbolize **state broadcasts** or multi-client responses triggered by the server after processing a message. Red solid arrows represent **client-initiated actions**, such as connection requests or interaction commands. The "thread" and "cookies" notes refer to the server's multithreading logic and internal session/state management, respectively.

### 🧵 Multithreading and State Tracking (**"Cookies"**)

The mention of *"cookies"* in this context is metaphorical. Just like web servers use cookies to **remember a user’s session** across multiple HTTP requests, our central server internally maintains **persistent information about each client** across different interactions. These include the client's :
- `Name`, Unique identifier (`ID`), Assigned `cards` or `objects`, `Connection status` and `Turn progression` 

This is crucial in a multithreaded architecture where the server spawns a **dedicated thread for each connected client**. Without this internal tracking (akin to a **cookie mechanism**), the server wouldn't be able to __personalize responses__ or __keep consistency in shared state__.

For instance, when a client receives a message such as :
- `D 1 3 5` - the server is distributing specific items (like cards) to that client.
- `V 1 1 1` - the server replies that client 1 holds object 1 exactly once.
- `M 1` - the server tells everyone that it’s client 1’s turn.

These messages are tailored to each client's internal session data. This “cookie-like” memory is what enables the system to behave coherently and synchronously, even under concurrent execution with threads.

### 🔌 Socket-Based Micro-Servers and Communication Model

Every client connects to the server through a **dedicated socket**, and from a design point of view, the main server can be imagined as **hosting four mini-servers internally** - one per active client. Each socket is paired with a thread, ensuring that all clients can communicate independently and simultaneously.

Once connected, a client has a persistent communication channel with the server :
- The server uses `send()` to **push messages** to a specific client.
- It can **broadcast** updates by writing to all sockets (e.g., when informing everyone of a new turn).
- Each thread reads from its socket using `recv()`, allowing real-time reactions to client actions.

This architecture allows the server to function like a **parallel dispatcher**, where each socket acts like a port to a virtual micro-service. These sockets and threads, combined with internal session tracking (the “cookies”), give the system robustness and flexibility for managing interactive, real-time multi-user logic.

---

## Sequence Diagram : Connection Flow

### ![Figure 2 - Connection and Initialization Sequence](./Useful_Resources/Images_ReadME/figure_2_sequence_connection.jpg)

This sequence diagram presents a detailed view of the initial connection phase and illustrates how the server responds to each new client. Below is a simplified version of the interaction timeline :


1. **Client Charlie** sends `C localhost 32003 Charlie` :
   - Server responds with `I 0\n`,
   - Sends `L Charlie - - - \n` to Charlie.

2. **Client Alice** sends `C localhost 32001 Alice`. The server responds with :
   - `I 1\n` (client ID),
   - `L Charlie Alice - - \n` to both Charlie and Alice.

3. **Client Bob** sends : `C localhost 32002 Bob`. The server sends :
   - `I 2\n` to Bob,
   - `L Charlie Alice Bob - \n` to Bob, Alice and Charlie.

4. **Client Donald** sends : `C localhost 32004 Donald` :
   - Responds with `I 3\n`,
   - Broadcasts `L Charlie Alice Bob Donald \n`. to all clients.

The key takeaway is how **each new client triggers a full-state update**, sent to **all previously connected clients**, ensuring that every client holds the most recent global state.

This diagram also highlights **threaded event management** : for each connection, the server spawns or delegates to a **thread, locks a mutex** during state modification, and triggers appropriate responses via a shared communication buffer.

---

## Implementation and System Concepts

In this section, we detail how the program was built, highlighting the use of various concepts explored during the practical sessions.

The project relies on a client-server architecture with message exchanges via sockets. The server is designed to handle multiple clients concurrently, with each client being managed by a dedicated thread. This model *suppose to* ensures server responsiveness, even when clients take time to respond or perform long actions.

### Socket Management

The server uses a TCP socket to listen for incoming connections. The `socket()` function creates a socket, which is then bound to an address and port using `bind()`. The server enters listen mode with `listen()` and waits for connections. When a client attempts to connect, the server accepts the connection using the `accept()` function, which returns a new communication socket specific to that connection. For each new connection, a thread is created using the `pthread_create()` function to handle that connection in isolation.

Each thread executes the `client_handler()` function, which receives the messages sent by the client and processes them based on the server’s current state (managed by a Finite State Machine, FSM). This mechanism allows each client to communicate independently with the server.

### Synchronization with Mutex

Since multiple threads may access the same shared data (e.g., the list of clients or the server's state), synchronization mechanisms are necessary to avoid race conditions. A mutex is used to ensure that modifications to shared data are done exclusively.

This locking mechanism secures simultaneous access to shared resources such as game state management or card distribution, ensuring data consistency and avoiding undefined behaviors.

### Processes and Communication with Pipes

While using threads is preferred in this project for its simplicity and speed, it is also possible to use processes and pipes for inter-process communication. In this case, each client could be handled in a separate process, further isolating interactions. However, given the simplified project model, a thread-based approach was chosen.

If processes had been used, each client process would be created via the fork() function, and communication between the server and its child processes could be done via named or anonymous pipes. Here's an example of creating a pipe between a parent and a child :
```c
int pipefd[2];
pipe(pipefd);
pid_t pid = fork();

if (pid == 0) 
{
    // Code executed by the child process
    close(pipefd[0]);
    write(pipefd[1], "Message", 7);
    close(pipefd[1]);
} 
else 
{
    // Code executed by the parent process
    close(pipefd[1]);
    char buffer[100];
    read(pipefd[0], buffer, sizeof(buffer));
    close(pipefd[0]);
} 
//Merci source Xioachen largement repris pour cette section
```
In this example, a pipe is created with pipe(), then a child process is generated with fork(). The child process sends a message to the parent process via the pipe, and the parent reads the message. While this approach is interesting for managing separate processes, it introduces additional complexity in terms of resource management and synchronization.

### Finite State Machine (FSM)

The server operates according to a Finite State Machine (FSM) model, which guides the evolution of its state based on the messages received. For example, in state 0, the server waits for client connections, while in state 1, the game is active, and players' actions are processed. State 2 represents the end of the game. This structure allows for the management of state transitions in an organized and predictable manner, which is essential for maintaining system consistency in a concurrent environment.

---

## Future Applications and Perspectives

Beyond the educational context and game-like framing, this project demonstrates the skeleton of a **real-time, concurrent client-server model**, highly applicable to modern systems. In **IoT infrastructures**, a centralized server coordinating sensor data streams from multiple devices could employ this same model. Clients (sensors) report data, and the server responds or broadcasts state changes across the network - all handled through thread-safe queues, FSMs for state validation, and asynchronous notification mechanisms. With adaptations, this could serve as a **base for smart home systems**, **monitoring platforms**, or **data aggregation pipelines** in distributed control systems.

Another relevant application lies in the realm of **collaborative tools** or **real-time multiplayer engines**, where many clients interact through actions that must be validated, sequenced, and rebroadcast. The FSM structure guarantees deterministic responses, while socket communication ensures scalability. By abstracting away the game-specific protocol and focusing on the architecture, this system becomes a potential **foundation for chat servers**, **interactive learning platforms**, or even **networked industrial control**. Its modularity makes it extendable with authentication, database logging, or persistent sessions using techniques such as forking processes or using named pipes for IPC.
