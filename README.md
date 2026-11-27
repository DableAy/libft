*This project has been created as part of the 42 curriculum by adabdall.*

# Libft

## Description

Libft is the first project of the 42 common core: a personal C library,
`libft.a`, that re-implements a set of standard libc functions and adds
extra string, output and linked-list utilities. The goal is to understand
how these basic building blocks work under the hood (memory handling,
pointers, allocation, edge cases) and to end up with a reusable library
for future 42 projects.

The library is written in C, follows the 42 Norm, uses no global variables,
and is built with `cc -Wall -Wextra -Werror` and `ar`.

## Instructions

### Requirements

- A C compiler available as `cc`
- `make` and `ar`

### Compilation

```sh
make        # builds libft.a at the root of the repository
make clean  # removes the object files
make fclean # removes the object files and libft.a
make re     # fclean + all
```

### Using the library

Include the header and link against the archive:

```c
#include "libft.h"

int	main(void)
{
	ft_putendl_fd("Hello from libft!", 1);
	return (0);
}
```

```sh
cc -Wall -Wextra -Werror main.c -L. -lft -o program
```

### Testing a single function

Every `ft_*.c` file ends with a small `main` inside a comment block. To try
one, uncomment it (or copy it into a separate file) and compile it with the
library, for example:

```sh
make
cc -Wall -Wextra -Werror test_split.c -L. -lft -o test_split && ./test_split
```

## Library overview

### Part 1 - Libc functions

Same prototypes and behaviour as the originals described in their man pages.

| Function | Description |
|---|---|
| `ft_isalpha` | Returns 1 if `c` is a letter, 0 otherwise |
| `ft_isdigit` | Returns 1 if `c` is a decimal digit, 0 otherwise |
| `ft_isalnum` | Returns 1 if `c` is a letter or digit, 0 otherwise |
| `ft_isascii` | Returns 1 if `c` is in the ASCII range 0-127, 0 otherwise |
| `ft_isprint` | Returns 1 if `c` is printable (32-126), 0 otherwise |
| `ft_strlen` | Length of a string |
| `ft_memset` | Fills `n` bytes of memory with a byte value |
| `ft_bzero` | Sets `n` bytes of memory to zero |
| `ft_memcpy` | Copies `n` bytes (areas must not overlap) |
| `ft_memmove` | Copies `n` bytes, safe for overlapping areas |
| `ft_strlcpy` | Size-bounded string copy, always NUL-terminates |
| `ft_strlcat` | Size-bounded string concatenation |
| `ft_toupper` | Converts a lowercase letter to uppercase |
| `ft_tolower` | Converts an uppercase letter to lowercase |
| `ft_strchr` | First occurrence of a character in a string |
| `ft_strrchr` | Last occurrence of a character in a string |
| `ft_strncmp` | Compares at most `n` characters of two strings |
| `ft_memchr` | Finds a byte in a memory area |
| `ft_memcmp` | Compares two memory areas |
| `ft_strnstr` | Finds a substring within the first `len` characters |
| `ft_atoi` | Converts a string to an `int` |
| `ft_calloc` | Allocates zero-initialised memory (unique pointer if a size is 0) |
| `ft_strdup` | Allocates a copy of a string |

### Part 2 - Additional functions

| Function | Description |
|---|---|
| `ft_substr` | New substring of `s` starting at `start`, at most `len` long |
| `ft_strjoin` | New string made of `s1` followed by `s2` |
| `ft_strtrim` | Copy of `s1` with characters of `set` removed from both ends |
| `ft_split` | NULL-terminated array of words of `s` split on `c` |
| `ft_itoa` | String representation of an integer (negatives handled) |
| `ft_strmapi` | New string from applying `f(index, char)` to each character |
| `ft_striteri` | Applies `f(index, &char)` to each character in place |
| `ft_putchar_fd` | Writes a character to a file descriptor |
| `ft_putstr_fd` | Writes a string to a file descriptor |
| `ft_putendl_fd` | Writes a string and a newline to a file descriptor |
| `ft_putnbr_fd` | Writes an integer to a file descriptor |

### Part 3 - Linked list

The list functions use the following structure, declared in `libft.h`:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

| Function | Description |
|---|---|
| `ft_lstnew` | Allocates a new node holding `content` |
| `ft_lstadd_front` | Adds a node at the beginning of a list |
| `ft_lstsize` | Counts the nodes of a list |
| `ft_lstlast` | Returns the last node of a list |
| `ft_lstadd_back` | Adds a node at the end of a list |
| `ft_lstdelone` | Frees one node and its content with `del` |
| `ft_lstclear` | Frees a whole list and sets the pointer to NULL |
| `ft_lstiter` | Applies `f` to the content of every node |
| `ft_lstmap` | Builds a new list from applying `f` to every node's content |

### Technical choices

- Helper functions are `static` to keep them local to their file.
- Functions reuse each other where it makes sense (e.g. `ft_strdup` uses
  `ft_strlen` and `ft_memcpy`, `ft_split` uses `ft_substr`).
- `ft_split` and `ft_lstmap` free everything they allocated if an
  allocation fails, so they never leak.
- `ft_itoa` and `ft_putnbr_fd` work on a `long` so `INT_MIN` is handled.
- The Makefile only rebuilds what changed and never relinks needlessly.

## Resources

- Linux man pages: `man 3 strlen`, `man 3 memmove`, `man 3 strlcpy`,
  `man 3 calloc`, etc.
- The 42 Norm (norminette) documentation.
- GNU Make manual: <https://www.gnu.org/software/make/manual/>
- *The C Programming Language*, B. W. Kernighan and D. M. Ritchie.
- Linked lists in C: <https://www.learn-c.org/en/Linked_lists>

### Use of AI

An AI assistant (Claude) was used on this project to:

- review the existing functions for bugs and Norm issues and propose
  corrected versions (notably `ft_split`, `ft_lstmap`, `ft_strlcpy`,
  `ft_substr`, `ft_strjoin`, `ft_strnstr`, `ft_itoa` and `ft_tolower`);
- write the small commented test `main` at the end of each file;
- clean up the Makefile and `libft.h`;
- draft this README.

All code was then read, tested and is understood by the author, who can
explain every function during evaluation.
