# Data Structures and Algorithms in C++

## Project Goal
The purpose of this repository is to implement fundamental data structures and algorithms from scratch using modern C++. This project serves as a practical deep dive into memory management, template programming, and algorithmic efficiency.

## Key Features
- **Professional Testing**: Every data structure is verified using the **GoogleTest** framework to ensure reliability and handle edge cases.
- **Generic Programming**: Extensive use of C++ templates to support various data types.
- **Memory Safety**: Focus on RAII principles, proper destruction, and dynamic memory reallocation.
- **Clean Code**: Organized structure with a clear separation between implementation and testing.

## Technologies Used
- **Language**: C++17/20
- **Compiler**: MSVC (Visual Studio 2026)
- **Unit Testing**: GoogleTest (gtest)
- **Version Control**: Git

## Roadmap & Progress

### Data Structures
- [x] **Stack** (Dynamic Array based)
- [ ] **Queue**
- [ ] **Singly Linked List**
- [ ] **Doubly Linked List**
- [ ] **Binary Search Tree**
- [ ] **Hash Table**

### Algorithms
- [ ] **Sorting**: Bubble, Insertion, QuickSort, MergeSort
- [ ] **Searching**: Binary Search
- [ ] **Graph Algorithms**: BFS, DFS

## How to Navigate
Each data structure is located in its own directory within `DataStructures/`. Inside each directory, you will find:
- `*.hpp`: The template-based implementation.
- `*Tests/`: A dedicated GoogleTest project for that specific structure.
