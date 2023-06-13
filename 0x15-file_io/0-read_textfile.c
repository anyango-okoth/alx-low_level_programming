#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Read text file and print to STDOUT.
 * @filename: Text file being read.
 * @letters: Number of letters to be read.
 *
 * Return: The actual number of bytes read and printed or 0 if NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t fp;
	ssize_t w;
	ssize_t r;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	fp = open(filename, O_RDONLY);
	if (fp == -1)
	{
		free(buffer);
		return (0);
	}

	r = read(fp, buffer, letters);
	if (r == -1)
	{
		free(buffer);
		close(fp);
		return (0);
	}

	w = write(STDOUT_FILENO, buffer, r);
	if (w == -1 || w != r)
	{
		free(buffer);
		close(fp);
		return (0);
	}

	free(buffer);
	close(fp);
	return (w);
}

