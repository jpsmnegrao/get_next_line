# get_next_line

## Description

A C function that reads from a file descriptor one line at a time, returning
each line on successive calls. Handles newline characters, end-of-file
conditions, and configurable buffer sizes. The bonus implementation supports
reading from multiple file descriptors independently.

# get_next_line

## Description

A C function that reads from a file descriptor one line at a time, returning each line on successive calls. Handles newline characters, end-of-file conditions, and configurable buffer sizes. The bonus implementation supports reading from multiple file descriptors independently.

## Instructions

### Main

The current `main.c` reads from standard input.

Compile:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

Run interactively:

```bash
./gnl
```

Or read from a file using input redirection:

```bash
./gnl < text.txt
```

To pass a filename directly as an argument, edit `main.c`: comment out the
current `main()` implementation and uncomment the version that opens a file
using `argv[1]`. Then compile with the same command and run:

```bash
./gnl text.txt
```

### Bonus

`main_bonus.c` accepts filenames as command-line arguments and reads from
multiple file descriptors.

Compile:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main_bonus.c -o gnl_bonus
```

Run with three files:

```bash
./gnl_bonus text.txt 42_with_nl.txt giant_line.txt
```

`BUFFER_SIZE` can be changed to test different read buffer sizes. Sample text
files are included in the repository.
