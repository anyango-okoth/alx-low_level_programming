#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: text file being read
 * @letters: number of letters to be read
 * Return: the actual number of bytes read and printed or 0 if NULL
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t fp;
	ssize_t w;
	ssize_t r;

	if (filename == NULL)
		return (-1);
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	fp = open(filename, O_RDONLY);
	r = read(fp, buffer, letters);
	w = write(STDOUT_FILENO, buffer, r);

	free(buffer);
	close(fp);
	return (w);
}

