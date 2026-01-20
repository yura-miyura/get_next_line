### _This project has been created as part of the 42 curriculum by yartym_

## get_next_line (gnl)

### **GNL** is a programming project that recreates the basic read-line functionality often seen in standard library functions (like `getline` or `fgets`).


## Description

The goal of this project is to create a function that returns a single line from a file descriptor. This requires the use of **static variables** to remember the position in the file and the remaining buffer between function calls.

## Algorithm Design

### Memory Management
The project uses static arrays instead of dynamic allocation (`malloc`) for the internal buffers. This is done to prevent **memory leaks**. 

If we used `malloc` and the user stopped reading a file before the end, the memory would stay allocated with no way to free it. By using static memory, we ensure the program remains leak-free regardless of how many lines are read.

### Code Reuse
Throughout both parts, standard helper functions (recreated from `libft`) are utilized. This demonstrates the ability to **reuse code** and adhere to standard C library behaviors.

## Features

### 1. Mandatory Part
The mandatory function handles reading from a **single file descriptor** at a time. It manages the buffer efficiently to return exactly one line (terminated by `\n` or EOF).

### 2. Bonus Part
The bonus implementation can manage **multiple file descriptors** simultaneously. You can alternate reading lines from `fd3`, `fd4`, and `fd5` without losing the reading thread of any file. Only one static variable have been used for bonus part.

# Instructions

## Usage

### 1. Create a Test File

You can copy the code below to test the **Mandatory** or **Bonus** versions.

#### Mandatory Test (`main.c`)
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(int ac, char **av)
{
	char    *line;
	int     fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (1);
		line = get_next_line(fd);
		while (line)
		{
			printf("%s", line);
			free(line);
			line = get_next_line(fd);
		}
		free(line);
		close(fd);
	}
}
```

#### Bonus Test (`main_bonus.c`)
```C
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int main(int ac, char **av)
{
	char    *line;
	int     fd;
	char    *line2;
	int     fd2;

	if (ac == 3)
	{
		fd = open(av[1], O_RDONLY);
		fd2 = open(av[2], O_RDONLY);

		line = get_next_line(fd);
		line2 = get_next_line(fd2);

		while (line || line2)
		{
			if (line)
			{
				printf("FD 1: %s", line);
				free(line);
				line = get_next_line(fd);
			}
			if (line2)
			{
				printf("FD 2: %s", line2);
				free(line2);
				line2 = get_next_line(fd2);
			}
		}
		close(fd);
		close(fd2);
	}
	return (0);
}
```
### 2. Compile
#### Mandatory:
```Bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```
#### Bonus:
```Bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main_bonus.c -o gnl_bonus
```
### 3. Run
```Bash
# Run mandatory with one file
./gnl get_next_line

# Run bonus with two files
./gnl_bonus get_next_line_bonus.c get_next_line_bonus.c
```
#### Resources

1) [GeelsForGeeks](https://www.geeksforgeeks.org/c/input-output-system-calls-c-create-open-close-read-write/)
2) [man read](https://man7.org/linux/man-pages/man2/read.2.html)
3) [man open](https://man7.org/linux/man-pages/man2/open.2.html)
4) [Gemini](https://gemini.google.com/share/e9be3fde2fa9)
