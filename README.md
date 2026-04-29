# push_swap

A stack sorting program written in C. Given a list of integers, **push_swap** outputs the shortest sequence of instructions needed to sort them in ascending order using only two stacks and a restricted set of operations.

---

## Table of Contents

- [Overview](#overview)
- [Algorithm](#algorithm)
- [Operations](#operations)
- [Project Structure](#project-structure)
- [Build](#build)
- [Usage](#usage)
- [Visualizer](#visualizer)
- [Requirements](#requirements)

---

## Overview

The program receives a set of integers as arguments, initializes **stack A** with them (in the given order), and **stack B** starts empty. It then prints to stdout the minimal sequence of moves that leaves stack A sorted in ascending order with stack B empty.

If the input is already sorted, no output is produced.

---

## Algorithm

| Stack size | Strategy |
|---|---|
| 1 | Already sorted — nothing to do |
| 2 | At most one `sa` |
| 3 | Hard-coded optimal sequence (`sort_three`) |
| ≥ 4 | **Turk algorithm** with quartile-based pre-sorting |

### Turk algorithm (≥ 4 elements)

1. Numbers are **indexed** by rank so comparisons are cost-free.
2. Elements below the **median** are pushed to stack B in two passes, separated by the **lower** and **upper quartiles**, giving B a partially pre-sorted structure.
3. For each node in B, the algorithm computes the **cheapest rotation cost** to bring both the node in B and its target position in A to the top simultaneously.
4. The cheapest node is pushed back to A (`pa`).
5. Once B is empty, the minimum of A is rotated to the top.

---

## Operations

| Instruction | Effect |
|---|---|
| `sa` | Swap the top two elements of stack A |
| `ra` | Rotate stack A upward (top → bottom) |
| `rb` | Rotate stack B upward |
| `rr` | `ra` + `rb` simultaneously |
| `rra` | Reverse rotate stack A (bottom → top) |
| `rrb` | Reverse rotate stack B |
| `rrr` | `rra` + `rrb` simultaneously |
| `pa` | Push top of B onto A |
| `pb` | Push top of A onto B |

---

## Project Structure

```
push_swap/
├── inc/
│   └── header.h                  # Shared types and function prototypes
├── srcs/
│   ├── algorithm/
│   │   ├── main.c                # Entry point, input parsing
│   │   ├── algorithm.c           # Dispatcher (sort_three / sort_turk)
│   │   ├── sort_3.c              # Hard-coded 3-element sort
│   │   ├── sort_turk.c           # Main Turk sorting loop
│   │   ├── initialise_stack_a.c  # Stack A initialisation
│   │   ├── node_initiation_b.c   # Cost computation for stack B nodes
│   │   ├── move_b_to_a.c         # Push cheapest node back to A
│   │   ├── push_under_median.c   # Quartile-based pre-push to B
│   │   └── find_quartile.c       # Median and quartile helpers
│   ├── commands/
│   │   ├── push.c                # pa / pb
│   │   ├── rotate.c              # ra / rb / rr
│   │   ├── reverse_rotate.c      # rra / rrb / rrr
│   │   └── swap.c                # sa
│   └── utils_functions/
│       ├── check_input.c         # Input validation
│       ├── sort_functions.c      # Index/min/max helpers
│       ├── stack_functions.c     # Linked-list utilities
│       └── utils.c               # Miscellaneous helpers
├── libft/                        # Custom C standard-library subset
├── obj/                          # Compiled object files (generated)
└── Makefile
```

---

## Build

### Prerequisites

- **clang** (or any C99-compatible compiler — adjust `CC` in the Makefile)
- **GNU Make**

### Targets

| Target | Description |
|---|---|
| `make` / `make all` | Build `push_swap` (compiles libft first) |
| `make clean` | Remove object files (`obj/`) |
| `make fclean` | `clean` + remove binaries and visualizer build |
| `make re` | Full rebuild (`fclean` + `all`) |
| `make visual` | Build everything and launch the visualizer |

```bash
# Standard build
make

# Clean build artifacts only
make clean

# Remove everything including the binary
make fclean

# Rebuild from scratch
make re
```

---

## Usage

```bash
# Sort a list of integers passed as separate arguments
./push_swap 3 1 4 1 5 9 2 6

# Pass integers as a single quoted string
./push_swap "3 1 4 1 5 9 2 6"

# Verify the output with a checker (example using ARG)
ARG="3 1 4 1 5 9 2 6"
./push_swap $ARG | ./checker $ARG
```

**Expected output of the checker:** `OK` if the sequence correctly sorts the input, `KO` otherwise.

### Error handling

The program writes `Error` to stdout and exits with status `-1` when:
- A non-integer argument is provided
- An integer is out of `INT` range
- Duplicate values are present

---

## Visualizer

A graphical visualizer is included as a git submodule ([o-reo/push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer)).

### First-time setup

```bash
# When cloning the repo for the first time:
git clone --recurse-submodules <your-repo-url>

# Or if already cloned without submodules:
git submodule update --init --recursive
```

### Launch

```bash
./visualizer        # builds everything on first run, then opens the GUI
```

The script automatically builds `push_swap` and the visualizer if not already compiled. Subsequent runs open the GUI directly.

```bash
make visual         # equivalent shorthand via make
```

### Updating the visualizer

```bash
cd push_swap_visualizer && git pull origin master
cd .. && git add push_swap_visualizer && git commit -m "Update visualizer submodule"
```

---

## Requirements

- C compiler with support for C99 or later
- POSIX-compatible environment (Linux / macOS)
- No external libraries — only the bundled `libft`
