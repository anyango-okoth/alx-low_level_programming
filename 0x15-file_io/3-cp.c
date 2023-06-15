#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

int openSourceFile(char *filename);
int createDestFile(char *filename);
void copyContent(int source_fd, int dest_fd);
void closeFile(int fd);

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int source_fd;
	int dest_fd;

	/* Check for the number of arguments */
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	/* Open the source file */
	source_fd = openSourceFile(argv[1]);

	/* Create or truncate the destination file */
	dest_fd = createDestFile(argv[2]);

	/* Copy the content from source file to destination file */
	copyContent(source_fd, dest_fd);

	/* Close the files */
	closeFile(source_fd);
	closeFile(dest_fd);

	return (0);
}

/**
 * openSourceFile - Opens the source file for reading.
 * @filename: The name of the source file.
 *
 * Return: The file descriptor for the opened file.
 */
int openSourceFile(char *filename)
{
	int source_fd = open(filename, O_RDONLY);

	if (source_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		exit(98);
	}
	return (source_fd);
}

/**
 * createDestFile - Creates or truncates the destination file for writing.
 * @filename: The name of the destination file.
 *
 * Return: The file descriptor for the created/truncated file.
 */
int createDestFile(char *filename)
{
	int dest_fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if (dest_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}
	return (dest_fd);
}

/**
 * copyContent - Copies the content from source to destination file
 * @source_fd: The file descriptor of the source file.
 * @dest_fd: The file descriptor of the destination file.
 */
void copyContent(int source_fd, int dest_fd)
{
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read;

	while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0)

	{
		ssize_t bytes_written = write(dest_fd, buffer, bytes_read);

		if (bytes_written == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to destination file\n");
			exit(99);
		}
	}

	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from source file\n");
		exit(98);
	}
}

/**
 * closeFile - Closes a file.
 * @fd: The file descriptor of the file to be closed.
 */
void closeFile(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

