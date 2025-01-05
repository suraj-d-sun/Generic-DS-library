# Generic DS Library in C

## Overview

This project implements a custom generic library in C for common data structures such as **Singly Linked List**, **Doubly Linked List**, **Stack**, and **Queue**. In C++, you can easily use STL and in Java, you have the collection classes, but in C, there is no built-in generic feature to handle different data types. This project aims to fill that gap by providing generic data structures in C that can store any kind of data type using pointers (`void *`).

## Why This Library?

While C++ and Java offer built-in collection classes for managing and sorting data, C does not have such capabilities. This project offers a way to implement data structures that can store any data type, including custom types, similar to how it is done in higher-level languages. This library helps build a deeper understanding of how data structures work and how you can manage data using custom implementations.

## Features

- **Singly Linked List (SLL)**
- **Doubly Linked List (DLL)**
- **Stack**
- **Queue**
- Generic data handling using `void *` pointers
- Type casting for data retrieval

## Functions
Each data structure (Singly Linked List, Doubly Linked List, Stack, Queue) includes functions for basic operations like:

- Create: Initialize a new data structure.
- Insert: Add elements to the data structure.
- Delete: Remove elements from the data structure.
- Traverse: Iterate over the data structure and retrieve elements.
- Destroy: Free the allocated memory.


## Setup and Installation
### Prerequisites
- **GCC** compiler or any C compiler that supports the `-I` and `-L` flags for header and library paths.

### Building the Library

1. **Clone the repository**:
    ```
    git clone <repository_url>
    cd Generic-DS-library
    ```

2. **Compile the source files**:
    For each data structure (Doubly Linked List, Singly Linked List, Stack, Queue), you will need to compile the `.c` files into object files (`.o`) and then link them together into a static library (`.a`).

    Example for building the combined library:
    ```bash
    gcc -c src/doubly/tm_doubly.c -I include/doubly -o src/doubly/tm_doubly.o
    gcc -c src/queue/tm_queue.c -I include/queue -o src/queue/tm_queue.o
    gcc -c src/singly/tm_singly.c -I include/singly -o src/singly/tm_singly.o
    gcc -c src/stack/tm_stack.c -I include/stack -o src/stack/tm_stack.o

    ar rcs lib/libtm_c_ds_combined.a src/doubly/tm_doubly.o src/queue/tm_queue.o src/singly/tm_singly.o src/stack/tm_stack.o
    ```

### Using the Library

Once the library is built, you can link it with your own C files by using the `-I` flag for the header files, the `-L` flag for the library directory, and the `-l` flag for specifying the library name.

Example:
```bash
gcc eg1.c -I include/ -L lib/ -ltm_c_ds_combined -o eg1.exe
```

