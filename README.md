# 🌐 Socket_Project_Network

>Last update: March 2026

A multi-language client-server communication demo implementing socket programming
concepts using **C**, **Java**, and **Python** — featuring multithreading and
multi-server/multi-user support.

---

## 📌 Overview

This project demonstrates how socket communication works at a low level and across
different programming languages. Each implementation handles multiple clients
simultaneously using threads, and supports communication through multiple servers.

---

## 🛠️ Tech Stack

| Language | Role |
|----------|------|
| `C` | Low-level socket implementation |
| `Java` | Object-oriented client-server model |
| `Python` | High-level socket scripting |

All implementations use **threads** to handle concurrent client connections.

---

## 📁 Project Structure
```
Socket_Project_Network/
├── Sockets-c/
│   ├── client.c
│   └── server.c
├── Sockets-cpp/
│   └── server_part/
├── Sockets-java/
│   └── sockets_project_rc_p1/
│       ├── src/main/java/
│       ├── pom.xml
│       └── .gitignore
├── Sockets-python/
│   ├── client.py
│   └── server.py
└── README.md
```

---

## ⚙️ How to Run

### C
```bash
gcc server.c -o server -lpthread
gcc client.c -o client
./server
./client
```

### Java
```bash
javac Server.java
javac Client.java
java Server
java Client
```

### Python
```bash
python server.py
python client.py
```

---

## ✨ Features

- ✅ Multi-language socket implementations (C, Java, Python)
- ✅ Multithreaded server — handles multiple clients concurrently
- ✅ Multi-server support
- ✅ Client-server communication over TCP/IP

---

## Useful links:  
https://www.geeksforgeeks.org/java/socket-programming-in-java/  
https://www.geeksforgeeks.org/cpp/handling-multiple-clients-on-server-with-multithreading-using-socket-programming-in-c-cpp/  
https://www.geeksforgeeks.org/system-design/client-server-model/  
https://www.digitalocean.com/community/tutorials/python-socket-programming-server-client  

--- 

## 📜 License

This project was developed **strictly for educational and academic purposes** as part
of a university assignment.

> ⚠️ This code is **not intended for production use**.
> Redistribution or commercial use is not permitted.
> You are free to study and reference this code for learning purposes only.



