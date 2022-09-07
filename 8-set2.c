#include "main.h"

/**
 * alloc_space - allocate space for list + NEW variable
 * @env: environment variables list
 *
 * Return: new env (Success) | NULL (Failure)
 */
char **alloc_space(char **env)
{
	char **new_env;
	unsigned int i;

	for (i = 0; env[i]; i++)
	{}
	new_env = malloc(sizeof(char *) * (i + 2));
	if (!new_env)
		return (NULL);
	for (i = 0; env[i]; i++)
	{
		new_env[i] = env[i];
		env[i] = NULL;
	}
	new_env[i++] = NULL, new_env[i] = NULL;

	return (new_env);
}

/**
 * new_var - create new environment variable string
 * @name: variable's name
 * @value: variable's value
 *
 * Return: 'nam=value' string (Succes) | NULL (Failure)
 */
char *new_var(char *name, char *value)
{
	char *var;
	size_t i, j;

	var = malloc(sizeof(char) * (_strlen(name) + _strlen(value) + 2));
	if (!var)
		return (NULL);

	for (i = 0; name[i]; i++)
		var[i] = name[i];

	var[i++] = '=';

	for (j = 0; value[j]; j++)
		var[i++] = value[j];

	var[i++] = '\0';

	return (var);
}

/**
 * get_name - gets the variable name from 'variable=value' string
 * @env_s: environment variable
 *
 * Return: name (Succes) | NULL (Failure)
 */
char *get_name(char *env_s)
{
	unsigned int i;
	char *name;

	if (!env_s)
		perror("NULL argument to get_name()"), exit(1);
	for (i = 0; env_s[i] && env_s[i] != '='; i++)
	{}
	if (!env_s[i])
		return (NULL);
	name = malloc(sizeof(char) * (++i));
	for (i = 0; env_s[i] && env_s[i] != '='; i++)
		name[i] = env_s[i];
	name[i] = '\0';
	return (name);
}

