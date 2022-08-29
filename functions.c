#include "main.h"

#define ARGS_SIZE 1000

/**
 * read_commad - reads command from user input
 * Return: pointer to allocated command string
 */
char *read_command(void)
{
	char *buffer;
	size_t i, j;

	i = 0;
	buffer = 0;
	if (getline(&buffer, &i, stdin) == -1)
	{
		buffer = NULL;
		return (buffer);
	}
	for (j = 0; buffer[j] != '\n'; j++)
	{
	while (j < i)
		buffer[j++] = '\0';
	return (buffer);
	}

/**
 * read_args - split given buffer into command and it's arguments
 * @buffer: given buffer
 *
 * Return: array of 'command and arguments' strings
 */
char **read_args(char *buffer)
{
	char **args;
	char *tok;
	const char *del;
	int n;

	args = malloc(sizeof(char *) * (ARGS_SIZE));
	if (!args)
		perror("Failed to allocate memory for args"), exit(1);
	
	del = "\t\n ";
	tok = strtok(buffer, del);
	n = 0;
	while (tok)
	{
		args[n++] = tok;
		tok = strtok(0, del);
	}
	for (; n < ARGS_SIZE; n++)
		args[n] = NULL;

	return (args);
}

/**
 * execute_command - executes given command if it exists
 * @args: array of strings containing the command and it's arguments
 * @env: environment variables
 *
 * Return: 1 (Succes) | 0 (Failure)
 */
int execute_command(char **args, __attribute__((unused))char **env)
{
	pid_t my_pid;

	my_pid = fork();
	if (!my_pid)
	{
		if (execve(args[0], args, env) == -1)
			perror(args[0]);
	}
	else if (my_pid < 0)
	{
		perror("Fork fail");
		return (0);
	}
	else
		wait(NULL);
	return (1);
}
