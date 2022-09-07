#include "main.h"

#define ARGS_SIZE 1000

/**
 * read_command - reads command from user input
 *
 * Return: pointer to allocated command string
 */
char *read_command(void)
{
	char *buffer;
	size_t i, j;

	i = 0;
	buffer = NULL;
	if (_getline(&buffer, &i, STDIN_FILENO) == -1)
	{
		buffer = NULL;
		return (buffer);
	}
	for (j = 0; buffer[j] != '\n'; j++)
	{}
	if (!j)
		j++;
	while (j < i)
		buffer[j++] = '\0';

	if (buffer)
		buffer = remove_comments(buffer);

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
	tok = _strtok(buffer, del);
	n = 0;
	while (tok)
	{
		args[n++] = tok;
		tok = _strtok(0, del);
	}
	for (; n < ARGS_SIZE; n++)
		args[n] = NULL;

	return (args);
}

/**
 * execute_command - executes given command if it exists
 * @args: array of strings containing the command and it's arguments
 * @env: environment variables
 * @exc: executable name (to be displayed with error message)
 *
 * Return: 1 (Succes) | 0 (Failure)
 */
int execute_command(char **args, char **env, char *exc)
{
	char **env_copy;
	char *path, *command;
	pid_t my_pid;

	env_copy = make_copy(env);
	path = get_PATH(env_copy);
	if (args && args[0])
		command = get_command(args[0], path);
	if (!args[0] || !command)
	{
		display_error(NULL, args[0], "not found");
		free(command), free_2D(env_copy);
		return (1);
	}

	my_pid = fork();
	if (!my_pid)
	{
		if (execve(command, args, env) == -1)
		{
			perror(exc);
			free(command), free_2D(env_copy);
			exit(1);
		}
	}
	else if (my_pid < 0)
	{
		perror("Fork fail");
		free(command), free_2D(env_copy);
		return (0);
	}
	else
		wait(NULL);

	free_2D(env_copy), free(command);
	return (1);
}
