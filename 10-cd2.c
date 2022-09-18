#include "main.h"

/**
 * same - check if start of two strings is identical
 * @s1: first string
 * @s2: second string
 *
 * Return: 1 (identical) | 0 (not)
 */
int same(char *s1, char *s2)
{
	unsigned int i;

	if (!s1 || !s2)
		return (0);

	for (i = 0; s1[i] && s2[i]; i++)
		if (s1[i] != s2[i])
			return (0);
	if (!s1[i] || !s2[i])
		return (1);

	return (0);
}

/**
 * get_var - get var string from environment variables list
 * @env: environment variables list
 * @var: variable to get
 *
 * Return: HOME (Success) | NULL (Failure)
 */
char *get_var(char **env, char *var)
{
	unsigned int i;

	for (i = 0; env[i]; i++)
	{
		if (same(env[i], var))
			return (env[i]);
	}
	return (NULL);
}

/**
 * get_dir - gets value of HOME
 * @home: home string
 *
 * Return: HOME's value
 */
char *get_dir(char *home)
{
	char *dir;
	unsigned int i, j;

	for (i = 0; home[i]; i++)
	{}
	dir = malloc(sizeof(char) * (i - 4));
	if (!dir)
		perror("Can't allocate memory for dir"), exit(1);
	j = 0;
	for (i = 0; home[i]; i++)
		if (home[i] == '=')
			break;
	for (++i; home[i]; i++)
		dir[j++] = home[i];
	dir[j] = '\0';

	return (dir);
}

/**
 * to_home - gets an environment variable value
 * @env: environment variables list
 * @var: variable to get
 *
 * Return: home directory (Success) | NULL (Failure)
 */
char *to_home(char **env, char *var)
{
	char *dir, *s;

	if (!env)
		return (NULL);
	s = get_var(env, var);
	if (!s)
		return (NULL);
	dir = get_dir(s);

	return (dir);
}
