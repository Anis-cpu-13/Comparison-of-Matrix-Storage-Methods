# Comparison-of-Matrix-Storage-Methods

## Introduction

This project is a semester-end project for the algorithm and advanced module, aiming to study the performance between different matrix storage structures, including compact matrix and vector. The program implements these structures and performs multiplication between them. The project also includes converting between the different structures.

## Usage

To compile the program, enter the command "make" and follow the steps displayed on the terminal.

## Implementation

The project consists of three .c files and two .h files. The structures.h file contains the declarations of the different structures, as well as the function signatures corresponding to the program's functionalities. The structures.c file contains the implementation of these structures, including the allocation of different structures, matrix and vector multiplication, and the conversion between structures. The tools.h file contains the signatures of the functions of a small dynamic allocation library that manages memory leaks by ensuring that the allocated memory space at the beginning of the program is equal to that released at the end. It also calculates the execution time of a function or part of the program using the gettimeofday function, calculating the interval between two variables "start" and "end."

## Difficulties Encountered

The main difficulties encountered were managing memory leaks, using pointers throughout the project, understanding and implementing the required structures, and deleting null elements in the compact matrix and vector structures.
Results

The program's results are presented and commented in two tables: Table 1 shows the execution time of multiplication operations, while Table 2 shows the memory allocated for each structure. Based on the comparison of execution times, the vector structure is the fastest, followed by the matrix structure, and finally the compact matrix structure. Regarding memory consumption, the matrix structure consumes the least, while the vector and compact matrix structures are equal. Unfortunately, the results are inconclusive as null elements were not deleted.

## Conclusion

The project's objective was to study different matrix storage structures and compare them in terms of memory consumption and execution time. The results show that the vector structure is the fastest, while the matrix structure consumes the least memory. However, further testing is required to reach a conclusion on the compact matrix structure. The deletion of null elements would provide more concise results.
License

### This project is licensed under the Apache License, Version 2.0. See the LICENSE file for more details.
