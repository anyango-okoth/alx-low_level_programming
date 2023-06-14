#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: A pointer to the file name.
 * @text_content: The string to add to the end of the file.
 *
 * Return: -1 If the function fails or filename is NULL.
 *         -1 If the file does not exist the user lacks write permissions
 *          1 success.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fp, bytes_obtained, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	fp = open(filename, O_WRONLY | O_APPEND);
	bytes_obtained = write(fp, text_content, len);

	if (fp == -1 || bytes_obtained == -1)
		return (-1);

	close(fp);

	return (1);
}

