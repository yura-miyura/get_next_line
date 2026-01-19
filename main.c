#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(int ac, char **av) {
  char *line;
  int fd;

  if (ac == 2) {
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
      return (1);

    line = get_next_line(fd);
    while (line) {
      printf("%s", line);
      free(line);
      line = get_next_line(fd);
    }
    free(line);
    close(fd);
  }
  return (0);
}
