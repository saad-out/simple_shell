#include "main.h"

/**
 * fill_buff - fills given line buffer with the text read
 * @line: line buffer
 * @buffer: buffer containing the read text
 *
 * Retrun: void
 */
void fill_buff(char *line, char *buffer)
{
	unsigned int i;

	line[0] = buffer[0];
	for (i = 1; buffer[i] && buffer[i - 1] != '\n'; i++)
		line[i] = buffer[i];

	line[++i] = '\0';
}

/**
 * _getline - reads an entire line from certain stream
 * @line: buffer to store line
 * @n: line buffer size
 * @fd: file descriptor to read from
 *
 * Return: number of read characters | -1 (Failure)
 */
ssize_t _getline(char **line, __attribute__((unused))size_t *n, int fd)
{
	static char buffer[1024];
	static int i;
	ssize_t size;
	int j;

	if (*(buffer + i) == '\0' || i >= 1024)
	{
		for (j = 0; j < 1024; j++)
			buffer[j] = '\0';
		size = read(fd, buffer, 1024), i = 0;
		if (!size || size == -1)
			return (-1);
	}

	size = 0;
	for (j = 0; buffer[i + j] && buffer[i + j] != '\n'; j++)
		size++;
	*n = ++size;
	*line = malloc(sizeof(char) * (size + 1));
	if (!(*line))
		printf("hh");
	fill_buff((*line), buffer + i);
	i += size;

	return (size);
}
