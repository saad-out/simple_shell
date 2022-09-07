#include "main.h"

/**
 * display_error - display error message on stderr
 * @executable: executable name
 * @cmd: command
 * @error: error message
 * Description: write an error message similar to /bin/sh when
 * an entered command is not found
 *
 * Return: void
 */
void display_error(char *executable, char *cmd, char *error)
{
	char *msg;
	static char *exec;
	static unsigned int n;
	unsigned int i, j;

	if (executable)
	{
		exec = executable;
		return;
	}

	if (!n)
		++n;

	i = _strlen(": 0: : \n") + _strlen(error);
	msg = malloc(sizeof(char) * (_strlen(exec) + _strlen(cmd) + i + 1));
	if (!msg)
		perror("Can't allocate memory for msg"), exit(1);

	for (i = 0; exec[i]; i++)
		msg[i] = exec[i];

	msg[i++] = ':', msg[i++] = ' ', msg[i++] = (n++) + '0';
	msg[i++] = ':', msg[i++] = ' ';

	if (cmd)
	{
		for (j = 0; cmd[j]; j++)
			msg[i++] = cmd[j];
		msg[i++] = ':', msg[i++] = ' ';
	}

	for (j = 0; error[j]; j++)
		msg[i++] = error[j];

	msg[i++] = '\n', msg[i] = '\0';
	write(STDERR_FILENO, msg, i), free(msg);
}
