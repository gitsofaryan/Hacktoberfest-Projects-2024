# Josephus Problem - Circular Linked List Implementation

This project implements the **Josephus Problem** using a circular linked list in C++.  
The Josephus problem is a classic algorithm/game where every k-th person in a circle is eliminated until only one person remains.

---

## 📋 Features
- Builds a circular linked list from user-provided names.  
- Prints the initial list of participants.  
- Runs the Josephus elimination algorithm based on the number of skips.  
- Outputs the winner of the game.  

---

## 🛠️ Requirements
- C++11 or later  
- A terminal/command-line environment  
- A C++ compiler such as:
  - `g++` (Linux/MacOS)
  - `clang++` (MacOS)
  - MinGW or MSVC (Windows)

---

## 🚀 Setup & Compilation

### Running the program
```bash
cd josephus-problem
g++ -std=c++11 -o josephus main.cpp
./josephus
```

### Usage

When prompted, provide:

`n` → number of participants (int)

`k` → number of skips (int)

A list of participant names (strings), ending with a `.`

**Example Input**
```
5 2
Alice
Bob
Charlie
Diana
Eve
.
```

**Example Output**
```
Alice
Bob
Charlie
Diana
Eve

Charlie wins!
```

## 📋 Notes

* Input ends when you type. or hit EOF.
* If invalid input is provided, the program throws a runtime_error.
* Memory is managed manually: the last remaining node is properly deleted at the end of execution.
