![Bannière](./Useful_Resources/Images_ReadME/banner.png)
# Modular_Threaded_Event_Coordinator_PECHEUX_S8

A modular C-based server component showcasing operating system-level concurrency and synchronization mechanisms. It supports coordinated asynchronous communication between multiple clients using threads, sockets, mutexes, and a finite state machine (FSM).

![Readme illustration](./Useful_Resources/Images_ReadME/Read_ME_0.png.gif)

---

## ⚙️ Repository Structure

The repository is organized as follows:

+ 🗂️ **[`Example_Application`](./Example_Application/Game_Educative_Application)** - A minimal demonstration scenario to test and explore the system behavior in a practical context.

+ 🗂️ **[`Useful_Resources`](./Useful_Resources)** - Contains visual resources and diagrams used in the documentation (FSM, sequence diagrams, architecture, etc.).

+ 🗂️ **[`Demo_Video`](./Demo_Video)** - Includes video demonstrations to visually showcase the coordinator's behavior and OS concepts in action.

+ 📄 **[`Vladislav_Levovitch_OS_Report.md`](./Vladislav_Levovitch_OS_Report.md)** - A technical report detailing the design choices and explaining how system-level OS concepts were applied.

+ ⚖️​ **`LICENSE`** : This project is licensed under the GNU GPL v3.


---

## 🛠️ General Instructions - 🧪 Example Application

The **[`Example_Application`](./Example_Application)** folder contains a self-contained use case to test the modular coordinator. This use case simulates multiple clients connecting to the server, interacting under the control of a shared FSM and triggering internal transitions.

### Dependencies and run
This project uses SDL2 for minimal graphical output and event handling simulation.
To run the project properly, we start by preparing everything in a **first terminal**. In this terminal, we will **clone** the repository, update the necessary **lib**raries, **compile** the code, and finally launch the **serv**er.

```bash
git clone git@github.com:Vladislav-Levovitch-Polytech-Sorbonne/Modular_Threaded_Event_Coordinator_PECHEUX_S8.git
cd Modular_Threaded_Event_Coordinator_PECHEUX_S8
sudo apt update
sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev
make
```

Once compiled, the server can be started using the following format : ```./1_server_begin_0.exe <port>```
```bash
./1_server_begin_0.exe 1991
```

Here, <port> must be a valid TCP port number, which usually falls between 1024 and 65535. Avoid ports below 1024 unless running as root, and make sure the port you choose isn't already in use by another service.

After the server is running, we need to launch the clients in **four different terminals**. Each client connects to the server and a module port (used for internal communication), and must be associated with a unique player name.

The general command to launch a client is: ```./2_client_begin_1_2_3.exe <server_ip> <server_port> <module_ip> <module_port> <player_name>```

In our example, for simplicity, we will use 127.0.0.1 for both IP addresses since we are running everything on the same machine. This is ideal for local testing, but of course the system is designed to work across real networks using distinct IP addresses.

Terminal 1
```bash
./2_client_begin_1_2_3.exe 127.0.0.1 1991 127.0.0.1 194712 Francois
```
Terminal 2
```bash
./2_client_begin_1_2_3.exe 127.0.0.1 1991 127.0.0.1 196105 Thibault
```
Terminal 3
```bash
./2_client_begin_1_2_3.exe 127.0.0.1 1991 127.0.0.1 197204 Vlad
```
Terminal 4
```bash
./2_client_begin_1_2_3.exe 127.0.0.1 1991 127.0.0.1 190408 Levovitch
```

Each terminal runs one independent client that communicates with the server and the other participants. Internally, each client spawns multiple threads: one to handle TCP communication, another for graphical display and events. This multithreaded and modular design allows smooth handling of events and real-time updates across distributed components.

## 💌​ Useful links and Acknowledgments

Ressources internet utilisées : https://www.geeksforgeeks.org/socket-programming-in-cpp/
https://www.codequoi.com/threads-mutex-et-programmation-concurrente-en-c/ version cpp disponible ici https://bousk.developpez.com/cours/reseau-c++/TCP/01-premiers-pas/
https://bousk.developpez.com/cours/multi-thread-mutex/
https://forum.trictrac.net/t/article-sherlock-13-le-detective-en-vacances-en-coree/208400 https://chatgpt.com/

Remerciement pour le ReadMe source reutilisé : Ayoub LADJiCi et des fichiers de Daniel FERREIRA LARA Readapted with gpt

Aide rédactionnelle, au débogage, au code, soutien et remerciement : Daniel, Yulin, Maxime, Ayman, Victor, Quentin, Ayoub, Keryann, Nicolas, ChatGPT, HARIAN Elyoth, Benjamin et Thibault HILAIRE