#include "main.h"

/**
 * print_exec - add executable to buffer
 * @buff: buffer
 * @exec: executable name
 * @n: error number
 *
 * Return: buff last index
 */
unsigned int print_exec(char *buff, char *exec, int n)
{
	unsigned int i;

	for (i = 0; exec[i]; i++)
		buff[i] = exec[i];

	buff[i++] = ':', buff[i++] = ' ';
	buff[i++] = n + '0';
	buff[i++] = ':', buff[i++] = ' ';

	return (i);
}

/**
 * print_command - adds command to buffer
 * @buff: buffer
 * @cmd: command
 * @i: buff last index
 *
 * Return: buffer last index
 */
unsigned int print_command(char *buff, char *cmd, unsigned int i)
{
	unsigned int j;

	if (!cmd)
		return (i);
	for (j = 0; cmd[j]; j++)
		buff[i++] = cmd[j];

	buff[i++] = ':', buff[i++] = ' ';

	return (i);
}

/**
 * print_error - adds error to buffer
 * @buff: buffer
 * @error: error message
 * @i: buffer last index
 *
 * Return: buffer last index
 */
unsigned int print_error(char *buff, char *error, unsigned int i)
{
	unsigned int j;

	for (j = 0; error[j]; j++)
		buff[i++] = error[j];

	return (i);
}

/**
 * print_more_text - adds text to buffer (if exists)
 * @buff: buffer
 * @text: added text
 * @index: char index
 * @i: buffer last index
 *
 * Return: buffer last index
 */
unsigned int print_more_text(char *buff, char *text, char index,
unsigned int i)
{
	unsigned int j;

	if (!text)
		return (i);

	if (index != 'c')
		buff[i++] = ':', buff[i++] = ' ';
	for (j = 0; text[j]; j++)
		buff[i++] = text[j];

	return (i);
}
/**
 * display_error - display error message on stderr
 * @executable: executable name
 * @cmd: command
 * @error: error message
 * @text: more text
 * Description: write an error message similar to /bin/sh when
 * an entered command is not found
 *
 * Return: void
 */
void display_error(char *executable, char *cmd, char *error, char *text)
{
	char *msg;
	static char *exec;
	static unsigned int n;
	unsigned int i;

	if (executable)
	{
		exec = executable;
		return;
	}

	if (!n)
		++n;
	msg = malloc(sizeof(char) * 100);
	if (!msg)
		perror("Can't allocate memory for msg"), exit(1);

	i = print_exec(msg, exec, n), n++;
	i = print_command(msg, cmd, i);
	i = print_error(msg, error, i);
	i = print_more_text(msg, text, error[0], i);

	msg[i++] = '\n', msg[i] = '\0';
	write(STDERR_FILENO, msg, i), free(msg);
}
