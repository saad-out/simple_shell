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
int main(__attribute__((unused))int ac, char **av, char **env)
{
	char *command, **args;
	int mode, ret;
	int (*f)(char *, char **, char **);

	mode = 1, ret = 1;
	while (mode && ret)
	{
		mode = isatty(STDIN_FILENO);
		if (mode)
			write(STDOUT_FILENO, "$ ", 2);
		command = read_command();
		if (!command || !(*command) || (command[0] == '\n'))
		{
			if (!command)
			{
				write(STDOUT_FILENO, "\n", 1);
				break;
			}
			free(command);
			continue;
		}

		args = read_args(command);
		if (!args || !args[0])
		{
			free(command), free(args);
			continue;
		}
		f = check_builtins(args[0]);
		if (f)
			ret = f(command, args, env);
		else
		{
			ret = execute_command(args, env, av[0]);
			free(command), free(args);
		}
	}
	return (0);
}
