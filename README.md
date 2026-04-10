# C++ Library Management System

## Description
This project is a modular library management system implemented in C++ as part of university coursework.

It demonstrates object-oriented programming, interface-based design, and structured software development using multiple modules.

---

## Features

- Management of different media types:
  - Books
  - DVDs
  - Magazines
  - Reference books

- Borrowable media interface (IBorrowable)
- Searchable media interface (ISearchable)
- Media collection and playlist management
- Modular and extensible system design

---

## Architecture

The project is organized into several components:

- media/
  Contains core media classes such as Book, DVD, Magazine, and ReferenceBook.

- management/
  Handles the main library logic, including collections and playlists.

- interfaces/
  Defines abstraction layers (IBorrowable, ISearchable) to ensure flexible design.

- util/
  Utility components such as logging and factory creation.

This modular structure improves maintainability and scalability.

---

## Technologies

- C++
- Object-Oriented Programming (OOP)
- Modular architecture
- Makefile build system

---

## Build & Run

make
./library-system

---

## Example Output

Library initialized
Added Book: C++ Programming
Borrow successful

---

## Learning Objectives

This project was developed to practice:

- Object-oriented design in C++
- Use of interfaces and abstraction
- Structuring multi-file software projects
- Build systems with Makefile
