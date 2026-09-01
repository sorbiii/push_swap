# Push Swap

A highly optimized sorting algorithm written in C, part of the 42 School curriculum. The goal is to sort data on stack A in ascending order using a limited set of instructions and a secondary stack B, executing the lowest possible number of actions.

## Requirements
* A UNIX-based operating system
* `gcc` or `clang` compiler
* `make`

## Compilation and execution

**1. Clone and compile:**
```bash
git clone https://github.com/sorbiii/push_swap.git
cd push_swap
make
```

**2. Run:**
Provide a list of unique integers as arguments. The program will output the operations needed to sort them:
```bash
./push_swap 4 67 3 87 23
```

## Operations Overview
The algorithm relies on these specific commands:
* **Swap:** `sa`, `sb`, `ss` (swaps the top two elements)
* **Push:** `pa`, `pb` (moves the top element from one stack to the other)
* **Rotate:** `ra`, `rb`, `rr` (shifts all elements up by one)
* **Reverse Rotate:** `rra`, `rrb`, `rrr` (shifts all elements down by one)
