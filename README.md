*This project has been created as part of the 42 curriculum by zaait-mo.*

# Libft

**Your first own C library**
# Description
Libft is a foundational C project from the 42 curriculum. The goal is to build a personal static library by reimplementing useful functions from the C standard library and creating additional utilities for strings, memory management, file-descriptor output, and linked lists.

Instead of relying entirely on ready-made functions, this project requires understanding how common operations work internally: traversing strings, manipulating memory byte by byte, allocating and freeing memory, handling edge cases, and managing dynamically allocated data structures.

The result is `libft.a`, a reusable library that can be linked into future C projects.

---

## Table of contents

- [Project objectives](#project-objectives)
- [Library contents](#library-contents)
  - [Part 1 — Libc functions](#part-1--libc-functions)
  - [Part 2 — Additional functions](#part-2--additional-functions)
  - [Part 3 — Linked-list functions](#part-3--linked-list-functions)
- [The linked-list structure](#the-linked-list-structure)
- [Project structure](#project-structure)
- [Compilation and usage](#compilation-and-usage)
- [Makefile rules](#makefile-rules)
- [Technical choices and constraints](#technical-choices-and-constraints)
- [Testing](#testing)
- [Resources](#resources)
- [Acknowledgements](#acknowledgements)

---

## Project objectives

The main objectives of Libft are to:

- Understand and reproduce the behavior of commonly used C library functions.
- Become comfortable with pointers, arrays, strings, and memory addresses.
- Practice dynamic memory allocation and correct memory cleanup.
- Learn to build and use a static library.
- Design and manipulate singly linked lists.
- Develop good habits around compilation, debugging, testing, and coding standards.

This library is intended to be useful throughout the 42 curriculum. Its functions can be reused in later projects whenever the project rules allow it.

## Library contents

The library is divided into three parts.

### Part 1 — Libc functions

This part reimplements selected functions from the C standard library. The project versions use the `ft_` prefix: for example, `strlen` becomes `ft_strlen`.

#### Character checks and conversions

| Function | Description |
|---|---|
| `ft_isalpha` | Checks whether a character is an alphabetic letter. |
| `ft_isdigit` | Checks whether a character is a decimal digit. |
| `ft_isalnum` | Checks whether a character is alphanumeric. |
| `ft_isascii` | Checks whether a value belongs to the ASCII range. |
| `ft_isprint` | Checks whether a character is printable. |
| `ft_toupper` | Converts a lowercase letter to uppercase. |
| `ft_tolower` | Converts an uppercase letter to lowercase. |

#### String operations

| Function | Description |
|---|---|
| `ft_strlen` | Calculates the length of a string. |
| `ft_strchr` | Finds the first occurrence of a character in a string. |
| `ft_strrchr` | Finds the last occurrence of a character in a string. |
| `ft_strncmp` | Compares two strings up to a specified number of characters. |
| `ft_strnstr` | Searches for a substring within a limited portion of another string. |
| `ft_strdup` | Allocates and returns a duplicate of a string. |
| `ft_strlcpy` | Copies a string into a destination buffer with a size limit. |
| `ft_strlcat` | Appends a string to a destination buffer with a size limit. |
| `ft_atoi` | Converts the initial numeric portion of a string to an integer. |

#### Memory operations

| Function | Description |
|---|---|
| `ft_memset` | Fills a memory area with a specified byte. |
| `ft_bzero` | Sets a memory area to zero. |
| `ft_memcpy` | Copies a specified number of bytes between memory areas. |
| `ft_memmove` | Copies bytes while safely handling overlapping memory areas. |
| `ft_memchr` | Searches a memory area for a byte. |
| `ft_memcmp` | Compares two memory areas byte by byte. |
| `ft_calloc` | Allocates memory for an array and initializes it to zero. |

### Part 2 — Additional functions

These functions extend the basic string and memory utilities with operations useful in everyday C programming.

#### String creation and transformation

| Function | Description |
|---|---|
| `ft_substr` | Creates a newly allocated substring. |
| `ft_strjoin` | Creates a new string by concatenating two strings. |
| `ft_strtrim` | Creates a copy of a string with selected characters removed from its beginning and end. |
| `ft_split` | Splits a string into a NULL-terminated array of separately allocated strings using a delimiter. |
| `ft_itoa` | Converts an integer into a newly allocated string. |
| `ft_strmapi` | Creates a new string by applying a function to each character, passing its index. |
| `ft_striteri` | Applies a function to each character, passing its index and the character's address so it can be modified. |

#### Output to file descriptors

These functions use `write()` to send data to a specified file descriptor.

| Function | Description |
|---|---|
| `ft_putchar_fd` | Writes one character to a file descriptor. |
| `ft_putstr_fd` | Writes a string to a file descriptor. |
| `ft_putendl_fd` | Writes a string followed by a newline. |
| `ft_putnbr_fd` | Writes an integer to a file descriptor. |

### Part 3 — Linked-list functions

The final part introduces a singly linked list. Each node stores a pointer to some content and a pointer to the next node.

| Function | Description |
|---|---|
| `ft_lstnew` | Allocates and initializes a new node. |
| `ft_lstadd_front` | Adds a node to the beginning of a list. |
| `ft_lstsize` | Counts the nodes in a list. |
| `ft_lstlast` | Returns the last node of a list. |
| `ft_lstadd_back` | Adds a node to the end of a list. |
| `ft_lstdelone` | Deletes one node, using a supplied function to delete its content. |
| `ft_lstclear` | Deletes a node and all following nodes, then sets the list pointer to `NULL`. |
| `ft_lstiter` | Applies a supplied function to the content of every node. |
| `ft_lstmap` | Creates a new list by applying a supplied function to each node's content. |

## The linked-list structure

The list uses the following structure, declared in `libft.h`:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

- `content` points to the data stored in the node. Its `void *` type allows the list to hold different data types.
- `next` points to the next node. It is `NULL` when the node is the last one.

A list is accessed through a pointer to its first node, often called the *head*. Functions that may change the head receive a pointer to that pointer (`t_list **`).

## Project structure

All project source and header files are placed at the repository root, as required by the subject.

```text
libft/
├── Makefile
├── libft.h
├── ft_*.c
└── README.md
```

The source files are compiled into object files (`.o`). Those object files are then collected into the static library `libft.a`.

# Instructions

## Compilation and usage

### Requirements

- A C compiler (`cc`).
- `make`.
- `ar`, to create the static library.

### Build the library

Clone the repository and enter its directory:

```bash
git clone <repository-url>
cd libft
```

Compile the library:

```bash
make
```

This creates `libft.a` in the project root.

### Use the library in a C program

Include the header in your source file:

```c
#include "libft.h"

int main(void)
{
    char *text;

    text = ft_strdup("Hello, Libft!");
    if (text == NULL)
        return (1);

    ft_putendl_fd(text, 1);
    free(text);
    return (0);
}
```

If your program uses `free()`, include `<stdlib.h>` as well. Compile your program and link it with the library:

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o program
```

Then run it:

```bash
./program
```

`-L.` tells the compiler's linker to look for libraries in the current directory. `-lft` links `libft.a` (the `lib` prefix and `.a` suffix are omitted in the option).

## Makefile rules

The Makefile provides the required targets:

| Command | Description |
|---|---|
| `make` or `make all` | Builds `libft.a`. |
| `make clean` | Removes the generated object files (`.o`). |
| `make fclean` | Runs `clean` and removes `libft.a`. |
| `make re` | Performs a full rebuild. |

The compilation uses:

```text
-Wall -Wextra -Werror
```

The Makefile uses `cc` to compile source files and `ar rcs` to create the static archive. It also declares the main targets as `.PHONY` and makes object files depend on `libft.h`, so header changes trigger recompilation.

## Technical choices and constraints

The implementation follows the mandatory-part requirements of the Libft subject:

- The project is written in C.
- The required compiler flags are `-Wall -Wextra -Werror`.
- The library is created with `ar`; `libtool` is not used.
- No global variables are declared.
- Helper functions are declared `static` when they are only needed within one source file.
- Source files are kept at the root of the repository.
- Dynamically allocated memory must be released when it is no longer needed.
- The library output, `libft.a`, is created at the repository root.

The functions are intended to follow the prototypes and behavior specified by the project subject and the relevant manual pages. As with standard C library functions, callers remain responsible for respecting each function's documented preconditions and ownership rules.

## Testing

Testing is an important part of developing this library. Each function should be checked with normal inputs, boundary cases, and relevant failure cases.

Useful checks include:

- Compile the project with `make`.
- Run your own test programs against the functions.
- Compare behavior with the corresponding system function where the subject permits it.
- Check linked-list operations with empty lists, one-node lists, and multi-node lists.
- Check allocation and cleanup paths to catch leaks and invalid frees.

The subject encourages keeping test programs for development and peer evaluation. Test files are not part of the required submission.

# Resources

The following references are useful when studying the concepts behind Libft:

The Libft subject (version 19.3) — the project specification, function requirements, constraints, and README requirements.

Linux manual pages — reference for standard functions and system calls. Use man 3 strlen, man 3 memcpy, man 3 atoi, and similar commands where available.

The C standard library documentation — useful for understanding standard function contracts and behavior.

GNU Make manual — https://www.gnu.org/software/make/manual/

cppreference: C language and library — https://en.cppreference.com/w/c

Google — used to search for technical information, documentation, and explanations of programming concepts.

YouTube — used to consult educational videos and tutorials about C programming and related concepts.

GeeksforGeeks – Input/Output System Calls in C — https://www.geeksforgeeks.org/c/input-output-system-calls-c-create-open-close-read-write/

CoderPad – An Introduction to Linked List Data Structures — https://coderpad.io/blog/development/an-introduction-to-linked-list-data-structures/

### AI usage

AI tools were used as a learning and reference resource throughout this project, in the same way as technical documentation, online articles, and educational videos.

They were used to:

Clarify C programming concepts and better understand topics such as pointers, memory management, strings, and linked lists.

Look up explanations of standard library functions, their behavior, and their edge cases.

Explore different approaches to programming problems and understand their underlying logic.

Support learning through explanations, examples, and discussions of implementation details.

Consult information about compilation, debugging, Makefiles, and static libraries.

AI was treated as an additional source of information, alongside official documentation, manual pages, and other educational resources. Information and suggestions were reviewed and checked against the project subject and relevant documentation.

## Acknowledgements

Thanks to the 42 / 1337 learning environment, peers, documentation authors, and everyone who shares knowledge and helps make difficult concepts easier to understand.

---

**Project:** Libft  
**Library:** `libft.a`  
**Author login:** `zaait-mo`
markdown
# Main title
## Section title
### Subsection title
#### Smaller heading