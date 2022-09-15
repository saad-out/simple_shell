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
	char *command, **args, **env_t;
	int i;

	env_t = make_copy(env), i = 1;

	/* Initialize display_error with the executable */
	display_error(av[0], NULL, NULL, NULL);

	while (i)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		command = read_command(env_t);
		args = read_args(command, env_t);
		i = execute_command(command, args, &env_t, av[0]);
		if (command)
			free(command);
		if (args)
			free(args);
	}
	free_2D(env_t);
	return (0);
}
