#include "main.h"

/**
 * main - simple shell
 * @ac: argument count
 * @av: argument vector (array of stings)
 * @env: array of strings containing environment variables
 *
 * Description: UNIX command line interpreter to execute commands
 * entered by user using a prompt for interactive mode and also
 * supporting non-interactive mode by taking commands as arguments
 *
 * Return: always 0 (Success)
 */
int main(__attribute__((unused))int ac, __attribute__((unused))char **av,
__attribute__((unused))char **env)
{
	char *command, **args;
	int mode, ret;

	mode = 1, ret = 1;
	while (mode && ret)
	{
		mode = isatty(STDIN_FILENO);
		if (mode)
			write(STDOUT_FILENO, "$ ", 2);
		command = read_command();
		if (!command)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		args = read_args(command);
		ret = execute_command(args, env);

		free(command);
		free(args);
	}
	return (0);
}
