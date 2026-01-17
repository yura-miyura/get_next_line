#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

#include "get_next_line.h"

int
main(int argc, char *argv[])
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	if (argc != 2) {
	fprintf(stderr, "Usage: %s <file>\n", argv[0]);
	exit(EXIT_FAILURE);
	}

	stream = fopen(argv[1], "r");
	if (stream == NULL) {
	perror("fopen");
	exit(EXIT_FAILURE);
	}


	while ((line = get_next_line(stream->_fileno)) != NULL) {
		printf("%s", line);
		free(line);
	}

	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}

