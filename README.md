c-task-manager — Console Todo List in C
------------------------------------------------------------

Short Description
------------------------------------------------------------
A beginner-friendly, console-based Todo List application written in pure C.
The goal is to help new C programmers practice core language concepts by building a small, useful CLI tool.

Project Goals
------------------------------------------------------------
- Learn and practice core C syntax and program structure
- Work with functions, arrays/pointers, and simple data structures
- Handle user input, menus, and control flow in a console app
- Read/write tasks to a file for basic persistence
- Compile and run a C program using GCC on Windows

Features
------------------------------------------------------------
- Add a new todo item
- List all todo items
- Mark a todo item as completed
- Delete a todo item
- Save tasks to a text file and load them at startup
- Simple, clean console interface

C Concepts Practiced
------------------------------------------------------------
- Program entry point (main) and modular functions
- Variables, arrays, and pointers
- struct for representing a todo item
- Control flow: if/else, switch, loops
- Standard I/O: printf, scanf, fgets
- File I/O: fopen, fclose, fprintf, fscanf
- Basic error handling and return codes

Folder Structure
------------------------------------------------------------
```
.
├─ README.md
└─ src/
	└─ main.c
	└─ task.c
	└─ task.h
```

How to Compile and Run (GCC on Windows)
------------------------------------------------------------
Prerequisites: Install GCC (e.g., via MinGW). Ensure gcc is available in your PATH.

Steps:
1) Open PowerShell in the project folder.
2) Compile the program:
	```bash
	scripts/build.ps1
	```
3) Run the program:
	```bash
	scripts/run.ps1
	```

Example Terminal Menu
------------------------------------------------------------
```
To-Do List Application
1. Add Task
2. View Tasks
3. Mark Task as Completed
4. Delete Task
5. Save Task in Disk
6. Exit
Enter your choice:
```

Future Improvements
------------------------------------------------------------
- Input validation and clearer error messages
- Edit task title and re-order tasks
- Colored output and improved formatting
- Configurable data file location
- Unit tests for core functions
- Cross-platform build instructions (Linux/macOS)

Who This Project Is For
------------------------------------------------------------
- Beginners learning C for the first time
- Students practicing console apps and basic data handling
- Anyone who wants a small, focused C project

License Note
------------------------------------------------------------
This project is open-source and intended for educational use. You may use, modify, and share it freely. If you plan to distribute, consider adding a permissive license (e.g., MIT) to clearly state terms.
