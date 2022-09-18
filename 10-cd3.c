#include "main.h"

/**
 * update_PWD - updates PWD environment variable
 * @env: environment variables list
 *
 * Return: 1 (Success) | -1 (Failure)
 */
int update_PWD(char **env)
{
	char cwd[100], *dir;
	size_t i;

	i = 100, getcwd(cwd, i);
	for (i = 0; env[i]; i++)
		if (same(env[i], "PWD"))
			break;
	if (!env[i])
		return (-1);
	dir = change_var(cwd, env, i);
	free(env[i]);
	env[i] = dir;
	return (1);
}

/**
 * update_OLDPWD - updates OLDPWD environment variable
 * @env: environment variables list
 * @val: value to update to
 *
 * Return: 1 (Success) | -1 (Failure)
 */
int update_OLDPWD(char **env, char *val)
{
	char *dir;
	unsigned int i;

	for (i = 0; env[i]; i++)
		if (same(env[i], "OLDPWD"))
			break;
	if (!env[i])
		return (-1);
	dir = change_var(val, env, i);
	free(env[i]);
	env[i] = dir;
	return (1);
}
