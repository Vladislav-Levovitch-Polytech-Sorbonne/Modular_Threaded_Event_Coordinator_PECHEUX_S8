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

### Dependencies
This project uses SDL2 for minimal graphical output and event handling simulation.

```bash
sudo apt update
sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev

```
```bash
make
```

## 💌​ Useful links and Acknowledgments

Ressources internet utilisées : https://www.geeksforgeeks.org/socket-programming-in-cpp/
https://www.codequoi.com/threads-mutex-et-programmation-concurrente-en-c/ version cpp disponible ici https://bousk.developpez.com/cours/reseau-c++/TCP/01-premiers-pas/
https://bousk.developpez.com/cours/multi-thread-mutex/
https://forum.trictrac.net/t/article-sherlock-13-le-detective-en-vacances-en-coree/208400 https://chatgpt.com/

Remerciement pour le ReadMe source reutilisé : Ayoub LADJiCi et des fichiers de Daniel FERREIRA LARA Readapted with gpt

Aide rédactionnelle, au débogage, au code, soutien et remerciement : Daniel, Yulin, Maxime, Ayman, Victor, Quentin, Ayoub, Keryann, Nicolas, ChatGPT, HARIAN Elyoth, Benjamin et Thibault HILAIRE