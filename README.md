# Push\_Swap

Push\_Swap is a project from 42 School that challenges you to sort a stack of integers using only a limited set of operations and another auxiliary stack. The goal is to implement a program that determines the most efficient way to sort the stack, with the fewest possible moves.

---

## Table of Contents

1. [Overview](#overview)
2. [Rules](#rules)
3. [Usage](#usage)
4. [Operations](#operations)
5. [Implementation](#implementation)
6. [Testing](#testing)
7. [Tips](#tips)

---

## Overview

The **push\_swap** program takes a list of integers as input, simulates a sorting process using two stacks (Stack A and Stack B), and outputs the sequence of operations needed to sort the numbers in ascending order.

The project is evaluated based on the number of moves used to sort the stack, so efficiency and optimization are key.

---

## Rules

1. **Stacks**: You have two stacks:

   - **Stack A**: Contains the initial set of integers.
   - **Stack B**: Auxiliary stack used for sorting.

2. **Operations**: You can only use a specific set of operations to manipulate the stacks (see the [Operations](#operations) section).

3. **Input Validation**: Your program must handle edge cases, such as invalid input, duplicates, or empty input.

4. **Output**: The program outputs a list of operations that sorts Stack A in ascending order.

5. **Evaluation**: The project is graded based on:

   - Correctness (does it sort correctly?)
   - Efficiency (number of moves used)
   - Code quality

---

## Usage

### Compilation

To compile the program, use the provided Makefile:

```bash
make
```

This generates the `push_swap` executable.

### Running the Program

Run the program with a sequence of integers as arguments:

```bash
./push_swap <list_of_numbers>
```

Example:

```bash
./push_swap 4 2 3 1
```

This will output a series of operations, such as:

```
pb
pb
ra
pa
pa
```

---

## Operations

Here are the allowed operations in **push\_swap**:

### Swap

- **sa**: Swap the first two elements of Stack A.
- **sb**: Swap the first two elements of Stack B.
- **ss**: Swap the first two elements of both stacks.

### Push

- **pa**: Push the top element of Stack B onto Stack A.
- **pb**: Push the top element of Stack A onto Stack B.

### Rotate

- **ra**: Rotate Stack A (first element becomes the last).
- **rb**: Rotate Stack B.
- **rr**: Rotate both stacks simultaneously.

### Reverse Rotate

- **rra**: Reverse rotate Stack A (last element becomes the first).
- **rrb**: Reverse rotate Stack B.
- **rrr**: Reverse rotate both stacks simultaneously.

---

## Implementation

1. **Input Validation**:

   - Ensure all arguments are valid integers.
   - Check for duplicates.
   - Handle edge cases (e.g., empty input).

2. **Algorithm**:

   - Implement sorting algorithms like:
     - Bubble Sort (for small stacks).
     - Quick Sort or Merge Sort variations (for larger stacks).
   - Optimize the number of moves based on stack size:
     - **2-3 elements**: Hard-code efficient moves.
     - **>3 elements**: Use more advanced sorting logic.

3. **Output**:

   - Print the operations required to sort the stack.

---

## Testing

Test your program with different cases to ensure correctness and efficiency:

### Basic Tests

- Simple inputs:
  ```bash
  ./push_swap 1 2 3
  ./push_swap 3 2 1
  ./push_swap 1 3 2
  ```

### Edge Cases

- Already sorted input:
  ```bash
  ./push_swap 1 2 3 4 5
  ```
- Reversed input:
  ```bash
  ./push_swap 5 4 3 2 1
  ```
- Large input:
  ```bash
  ./push_swap $(seq 1 100 | shuf)
  ```

### Checker

To validate your output, use the **checker** program (if implemented):

```bash
./push_swap 3 2 1 | ./checker 3 2 1
```

The checker will confirm if the stack is sorted and whether the moves are valid.

---

## Tips

Manage the following input

```
./push_swap ""
```

---

## Author

This project was completed as part of the 42 School curriculum. For any questions or feedback, feel free to reach out!



