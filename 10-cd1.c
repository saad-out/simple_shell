#include "main.h"

/**
 * cd - changes current working directory
 * @command: entered command
 * @args: command's arguments
 * @env: environment variables list
 *
 * Return: always 1
 */
int cd(__attribute__((unused))char *command, char **args, char ***env)
{
	char *dir, *ret;
	char old[100];
	size_t i;

	if (args && args[0] && !args[1])
		dir = to_home(*env, "HOME");
	else if (args && args[0] && !_strcmp(args[1], "-") && !args[2])
		dir = to_home(*env, "OLDPWD");
	else
		dir = _copy(args[1]);

	i = 100, ret = getcwd(old, i);
	if (!ret)
		perror("Can't get current working directory");
	if (!dir)
		display_error(NULL, args[0], "can't cd to OLDPWD", NULL);
	else if (chdir(dir) == -1)
		display_error(NULL, args[0], "can't cd to ", dir);
	else
		update_PWD(*env), update_OLDPWD(*env, old);

	free(dir);
	return (1);
}
