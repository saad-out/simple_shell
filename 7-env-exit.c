#include "main.h"

/**
 * print_env - print list of environment variables
 * @command: entered command (to be freed)
 * @args: command's arguments (to be freed)
 * @env: environment variables list
 *
 * Return: always 1
 */
int print_env(char *command, char **args, char ***env)
{
	int i;

	if (!command || !args || !env)
		perror("NULL arument to print_env()"), exit(1);

	for (i = 0; (*env)[i]; i++)
	{
		write(STDOUT_FILENO, (*env)[i], _strlen((*env)[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (1);
}

/**
 * my_atoi - converts number from string to unsigned int
 * @n: given number
 *
 * Return: number | -1 (Failure)
 */
int my_atoi(char *n)
{
	unsigned int a, num;
	int i;

	num = i = 0;
	while (n[i])
	{
		if (n[i] < '0' || n[i] > '9')
			return (-1);
		i++;
	}
	--i;
	a = 1;
	while (i >= 0)
	{
		num += (n[i] - 48) * a;
		a *= 10;
		i--;
	}
	return (num);
}

/**
 * perform_exit - exits with specefic status
 * @command: entered command (to be freed)
 * @args: command's arguments (to be freed)
 * @env: environment variables list
 *
 * Return: do not return (Succes) | 1 (Failure)
 */
int perform_exit(char *command, char **args, char ***env)
{
	int status;

	if (!command || !args || !env)
		perror("NULL arument to print_env()"), exit(1);

	if (!args[1])
		status = 0;
	else
	{
		status = my_atoi(args[1]);
		if (status == -1)
		{
			display_error(NULL, command, "Illegal number", args[1]);
			return (1);
		}
	}
	free(command), free(args), free_2D(*env);
	exit(status);
	return (1);
}
