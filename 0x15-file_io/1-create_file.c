#include "main.h"

/**
 * create_file - Creates a file.
 * @filename: A pointer to file name to be  created.
 * @text_content: A pointer to a string to write to the file.
 *
 * Return: -1 If the function fails
 *          1 on sucess
 */
int create_file(const char *filename, char *text_content)
{
	int fp, bytes_obtained, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	fp = open(filename, O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR);
	bytes_obtained = write(fp, text_content, len);

	if (fp == -1 || bytes_obtained == -1)
		return (-1);

	close(fp);

	return (1);
}

