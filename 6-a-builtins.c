#include "main.h"

/**
 * check_builtins - check if entered command is a builtin
 * @command: given command
 *
 * Return: function pointer to execute builtin | NULL (not a builtin:
 */
int (*check_builtins(char *command))(char *, char **, char **)
{
	bt list[] = {
		{"env", print_env},
		{"exit", perform_exit},
		{NULL, NULL}
	};
	int i;

	for (i = 0; list[i].cmd; i++)
		if (!_strcmp(command, list[i].cmd))
			return (list[i].f);
	return (NULL);
}
