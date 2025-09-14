
# COS110 Day 1 & 2: Practical 1 - Pointers and Dynamic Arrays

## Introduction

Good day, good people!The purpose of this practical is to cover the fundamental concepts from Days 1 and 2: **pointers** and **dynamic memory allocation** in one go, because of the delays we've had.

### The Story

Gintoki (from the anime Gintama) runs a business called "Odd Jobs Gin" where he does random jobs for money. Unfortunately, he spends all his earnings on strawberry milk and sweets, leaving him unable to pay rent. His landlady Otose is tired of excuses and demands a proper tracking system for his rent payments (or lack thereof).

Your job is to build this system using dynamic 2D arrays and proper memory management.

## Learning Outcomes
After completing this practical, you will be able to:
- Create and manipulate pointers
- Allocate dynamic memory using `new` and `delete`
- Create and manage 2D dynamic arrays
- Prevent memory leaks through proper cleanup
- Understand the difference between stack and heap memory

## Theory Review

### Pointers Basics
```cpp
int x = 5;          // Regular variable
int* p = &x;        // p points to x
cout << *p;         // Prints 5 (dereference p)
```

### Dynamic Memory
```cpp
// Stack allocation (automatic)
int arr[10];        

// Heap allocation (manual)
int* arr = new int[10];
// ... use array ...
delete[] arr;       // MUST clean up!
```

### 2D Dynamic Arrays
A 2D array is really an array of pointers to arrays:

```cpp
int** matrix = new int*[rows];     // Array of row pointers
for(int i = 0; i < rows; i++) {
    matrix[i] = new int[cols];     // Each row is an array
}
```

Visual representation:
```
matrix → [ptr0] → [0][0][0][0]
         [ptr1] → [0][0][0][0]
         [ptr2] → [0][0][0][0]
```

### Memory Cleanup
```cpp
// Delete in reverse order of creation
for(int i = 0; i < rows; i++) {
    delete[] matrix[i];    // Delete each row
}
delete[] matrix;           // Delete the array of pointers
```

## The Task

You need to implement a rent tracking system using a 2D dynamic array where:
- Rows represent months (0-11)
- Columns represent expense categories (rent, food, strawberry milk, etc.)

### Data Structure
```cpp
struct RentTracker {
    int** expenses;      // 2D array [month][category]
    int numMonths;       // Number of months to track
    int numCategories;   // Number of expense categories
};
```

## Functions to Implement

You must implement these functions in `src/RentTracker.cpp`:

### 1. `createTracker(int months, int categories)`
- Allocate memory for the RentTracker struct
- Create the 2D array with given dimensions
- Initialize all values to 0
- Return pointer to the tracker

### 2. `recordExpense(RentTracker* tracker, int month, int category, int amount)`
- Record an expense in the specified month and category
- Validate that month and category are within bounds

### 3. `getMonthTotal(RentTracker* tracker, int month)`
- Calculate total expenses for a specific month
- Return -1 if month is invalid

### 4. `getCategoryTotal(RentTracker* tracker, int category)`
- Calculate total expenses for a specific category across all months
- Return -1 if category is invalid

### 5. `findWorstMonth(RentTracker* tracker)`
- Find the month with highest total expenses
- Return the month index (0-11)

### 6. `calculateAverage(RentTracker* tracker)`
- Calculate average monthly expenses
- Return as integer (use integer division)

### 7. `copyTracker(RentTracker* original)`
- Create a deep copy of the tracker
- Allocate new memory for the copy
- Copy all values from original

### 8. `clearMonth(RentTracker* tracker, int month)`
- Set all expenses for a specific month to 0
- Validate month index

### 9. `printReport(RentTracker* tracker)`
Print in this format:
```
=== Expense Report ===
Month 0: [100] [200] [50] | Total: 350
Month 1: [100] [150] [75] | Total: 325
...
Grand Total: XXXX
```

### 10. `destroyTracker(RentTracker* tracker)`
- Free ALL allocated memory
- Delete in correct order to prevent leaks

## Getting Started

### Option 1: GitHub Codespaces (Recommended)
1. Fork this repository
2. Click "Code" → "Codespaces" → "Create codespace"
3. Wait for environment setup
4. Start coding!

### Option 2: Local Development
```bash
git clone https://github.com/YOUR_USERNAME/COS110-DAY1AND2-PRAC1.git
cd COS110-DAY1AND2-PRAC1
make
```

## Testing Your Code

```bash
make           # Compile your code
make test      # Run tests
make memcheck  # Check for memory leaks (IMPORTANT!)
make clean     # Clean compiled files
```

## Debugging Tips

### Common Errors and Solutions

**Segmentation Fault**
- Accessing NULL pointer
- Array index out of bounds
- Using deleted memory

**Memory Leaks** (detected by valgrind)
- Missing `delete` for a `new`
- Missing `delete[]` for a `new[]`
- Not deleting in correct order

**Wrong Output**
- Check loop bounds
- Verify array indices
- Print debug statements

## Assessment Criteria

- **Functionality (60%)**: Passing test cases
- **Memory Management (40%)**: No memory leaks in valgrind

**Important**: Memory leaks result in significant mark deduction!



## Quick Reference

### Pointer Operations
```cpp
int* p = new int;       // Allocate single int
int* arr = new int[n];  // Allocate array
delete p;               // Delete single
delete[] arr;           // Delete array
```

### 2D Array Pattern
```cpp
// Allocate
int** arr = new int*[rows];
for(int i = 0; i < rows; i++)
    arr[i] = new int[cols];

// Deallocate
for(int i = 0; i < rows; i++)
    delete[] arr[i];
delete[] arr;
```



Good luck! May your code be leak-free! 🫡
```

## File 2: .devcontainer/devcontainer.json

```json
{
  "name": "COS110 C++98 Development",
  "image": "mcr.microsoft.com/devcontainers/cpp:ubuntu-22.04",
  "features": {
    "ghcr.io/devcontainers/features/common-utils:2": {}
  },
  "customizations": {
    "vscode": {
      "extensions": [
        "ms-vscode.cpptools",
        "ms-vscode.cpptools-extension-pack"
      ],
      "settings": {
        "C_Cpp.default.cppStandard": "c++98",
        "files.associations": {
          "*.h": "cpp",
          "*.cpp": "cpp"
        }
      }
    }
  },
  "postCreateCommand": "sudo apt-get update && sudo apt-get install -y valgrind make g++ && echo 'Environment ready!'",
  "remoteUser": "vscode"
}
```

## File 3: src/RentTracker.h

```cpp
#ifndef RENTTRACKER_H
#define RENTTRACKER_H

struct RentTracker {
    int** expenses;      // 2D array [month][category]
    int numMonths;       // Number of months
    int numCategories;   // Number of expense categories
};

// Create and initialize tracker
RentTracker* createTracker(int months, int categories);

// Record an expense
void recordExpense(RentTracker* tracker, int month, int category, int amount);

// Get total for a month
int getMonthTotal(RentTracker* tracker, int month);

// Get total for a category
int getCategoryTotal(RentTracker* tracker, int category);

// Find month with highest expenses
int findWorstMonth(RentTracker* tracker);

// Calculate average monthly expense
int calculateAverage(RentTracker* tracker);

// Create deep copy
RentTracker* copyTracker(RentTracker* original);

// Clear a month's data
void clearMonth(RentTracker* tracker, int month);

// Print report
void printReport(RentTracker* tracker);

// Clean up memory
void destroyTracker(RentTracker* tracker);

#endif
```

## File 4: src/RentTracker.cpp (Student Template)

```cpp
#include "RentTracker.h"
#include <iostream>
using namespace std;

// Function 1: Create and initialize tracker
RentTracker* createTracker(int months, int categories) {
    // TODO: Implement this function
    return NULL;
}

// Function 2: Record an expense
void recordExpense(RentTracker* tracker, int month, int category, int amount) {
    // TODO: Implement this function
}

// Function 3: Get total for a month
int getMonthTotal(RentTracker* tracker, int month) {
    // TODO: Implement this function
    return -1;
}

// Function 4: Get total for a category
int getCategoryTotal(RentTracker* tracker, int category) {
    // TODO: Implement this function
    return -1;
}

// Function 5: Find month with highest expenses
int findWorstMonth(RentTracker* tracker) {
    // TODO: Implement this function
    return 0;
}

// Function 6: Calculate average monthly expense
int calculateAverage(RentTracker* tracker) {
    // TODO: Implement this function
    return 0;
}

// Function 7: Create deep copy
RentTracker* copyTracker(RentTracker* original) {
    // TODO: Implement this function
    return NULL;
}

// Function 8: Clear a month's data
void clearMonth(RentTracker* tracker, int month) {
    // TODO: Implement this function
}

// Function 9: Print report
void printReport(RentTracker* tracker) {
    // TODO: Implement this function
}

// Function 10: Clean up memory
void destroyTracker(RentTracker* tracker) {
    // TODO: Implement this function
}
```

## File 5: Makefile

```makefile
CXX = g++
CXXFLAGS = -Wall -g -std=c++98 -pedantic
TARGET = renttracker
OBJS = src/main.o src/RentTracker.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

test: tests/testMain.o src/RentTracker.o
	$(CXX) $(CXXFLAGS) -o test_runner tests/testMain.o src/RentTracker.o
	./test_runner

memcheck: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

clean:
	rm -f src/*.o tests/*.o $(TARGET) test_runner

.PHONY: all test memcheck clean
```

## File 6: .gitignore

```
*.o
*.out
renttracker
test_runner
.vscode/
*.swp
vgcore.*
```

## To Deploy on GitHub:

1. Create repository named `COS110-DAY1AND2-PRAC1`
2. Initialize locally:
```bash
git init
git add .
git commit -m "Initial practical setup"
git remote add origin https://github.com/SwiftTuition/COS110-DAY1AND2-PRAC1.git
git push -u origin main
```

3. Enable GitHub Codespaces in repository settings

This practical is specifically designed for Days 1-2 of COS110, focusing on fundamental pointer concepts and 2D dynamic arrays with proper memory management.
