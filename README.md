# Package Tracking System

## Overview

The Package Tracking System is a simple program that enables users to add, display, update, and save package information in a hash table. It provides a basic implementation of a package tracking system using the C programming language.

## Features

- **Add Package:** Add a new package to the tracking system.
- **Display Package:** Display information about a specific package.
- **Update Package:** Update information about a specific package.
- **Display All Packages:** Display information about all packages in the system.
- **Save to File:** Save package information to a txt file.

## Getting Started

### Prerequisites

- GCC (GNU Compiler Collection)
  - Make sure you have a C compiler installed on your system.

### Compilation

```bash
gcc -c Main.c -o Main.o
gcc -c HashTable.c -o HashTable.o
gcc Main.o HashTable.o -o PackageTrackingSystem
```

## Usage

```bash
./PackageTrackingSystem
```

Follow the on-screen prompts to interact with the Package Tracking System.

## File Structure
- **Doc folder:** Contains Doxygen documentation.
- **Main.c:** Contains the main function and user interface.
- **HashTable.h/HashTable.c:** Implements hash table functions.
- **Node.h/Node.c:** Defines the node structure for the hash table.
- **Package.h:** Defines the package structure.
- **README.md:** Project documentation.

## License

This project is licensed under the MIT License.

## Acknowledgments

- This project was created as a simple example for learning purposes.
- Feel free to customize and extend it based on your needs.
