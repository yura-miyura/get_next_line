### This project has been created as part of the 42 curriculum by yartym

## get_next_line

### `gnl` is a program that recretes basic read-file functionality of cat command 

## About
This project aimed to create useful functions within a single static library. It involves recreating various standard C library functions, as well as additional utility functions and linked list manipulation tools.

## List of Functions

### 1. Libc Functions
Standard C library functions recreated to understand the underlying logic.

| Function | Description |
| :------- | :---------- |
| `ft_isalpha` | Checks for an alphabetic character. |
| `ft_isdigit` | Checks for a digit (0 through 9). |
| `ft_isalnum` | Checks for an alphanumeric character. |
| `ft_isascii` | Checks whether c fits into the ASCII character set. |
| `ft_isprint` | Checks for any printable character. |
| `ft_strlen` | Calculates the length of a string. |
| `ft_memset` | Fills memory with a constant byte. |
| `ft_bzero` | Zeroes a byte string. |
| `ft_memcpy` | Copies memory area. |
| `ft_memmove` | Copies memory area (handles overlapping). |
| `ft_strlcpy` | Copies string to a specific size. |
| `ft_strlcat` | Concatenates string to a specific size. |
| `ft_toupper` | Converts char to uppercase. |
| `ft_tolower` | Converts char to lowercase. |
| `ft_strchr` | Locates character in string (first occurrence). |
| `ft_strrchr` | Locates character in string (last occurrence). |
| `ft_strncmp` | Compares two strings. |
| `ft_memchr` | Scans memory for a character. |
| `ft_memcmp` | Compares memory areas. |
| `ft_strnstr` | Locates a substring in a string. |
| `ft_atoi` | Converts a string to an integer. |
| `ft_calloc` | Allocates memory and sets its bytes' values to 0. |
| `ft_strdup` | Creates a duplicate for the string passed as parameter. |

### 2. Additional Functions
Useful utility functions for string manipulation and file output.

| Function | Description |
| :------- | :---------- |
| `ft_substr` | Returns a substring from a string. |
| `ft_strjoin` | Concatenates two strings. |
| `ft_strtrim` | Trims the beginning and end of string with specified set of chars. |
| `ft_split` | Splits a string using a char as parameter. |
| `ft_itoa` | Converts a number into a string. |
| `ft_strmapi` | Applies a function to each character of a string. |
| `ft_striteri` | Applies a function to each character of a string (by reference). |
| `ft_putchar_fd` | Outputs a char to a file descriptor. |
| `ft_putstr_fd` | Outputs a string to a file descriptor. |
| `ft_putendl_fd` | Outputs a string to a file descriptor, followed by a newline. |
| `ft_putnbr_fd` | Outputs a number to a file descriptor. |

### 3. Linked List Functions
Functions to manipulate linked lists (`t_list`).

| Function | Description |
| :------- | :---------- |
| `ft_lstnew` | Creates a new list element. |
| `ft_lstadd_front` | Adds an element at the beginning of a list. |
| `ft_lstsize` | Counts the number of elements in a list. |
| `ft_lstlast` | Returns the last element of the list. |
| `ft_lstadd_back` | Adds an element at the end of a list. |
| `ft_lstdelone` | Deletes and frees an element from the list. |
| `ft_lstclear` | Deletes and frees the given element and every successor. |
| `ft_lstiter` | Applies a function to the content of all list's elements. |
| `ft_lstmap` | Applies a function to the content of all list's elements into new list. |

## Installation 

Create static library with Makefile

```bash
make
```
## Usage

### 1. Include the heade in your C file:

```C
#include "libft.h"

int main(void)
{
    ft_putstr_fd("Hello, Libft!", 1);
    return (0);
}
```

### 2. Compile your project:

```bash
cc <file_name>.c -L. -lft -o <file_name>
```

* `-L.` tells the compiler to look for libraries in the current directory.

* `-lft` links the libft library (the compiler automatically adds the lib prefix and .a suffix).

## Resources

1) [CS50](https://www.youtube.com/watch?v=HJP0a6vKvlo&list=PLhQjrBD2T380hlTqAU8HfvVepCcjCqTg6)
2) [man](https://man7.org/)
3) [google](https://www.google.com/)
