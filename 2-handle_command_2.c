#include "main.h"

/**
 * full_path - gets full path of a command/program
 * @cmd: entered command/program
 * @env: environment variables list
 *
 * Return: pointer to full path command
 */
char *full_path(char *cmd, char **env)
{
	char **env_copy;
	char *full_cmd, *path;

	if (!cmd || !env)
		perror("NULL argument to full_path()"), exit(1);
	if (cmd && (cmd[0] == '/' || cmd[0] == '.'))
	{
		full_cmd = malloc(sizeof(char) * (_strlen(cmd) + 1));
		if (!full_cmd)
			perror("Can't allocate memory for full_cmd"), exit(1);
		full_cmd = _strcpy(full_cmd, cmd);
		return (full_cmd);
	}

	env_copy = make_copy(env);
	path = get_PATH(env_copy);
	full_cmd = get_command(cmd, path);
	free_2D(env_copy);
	return (full_cmd);
}

/**
 * get_PATH - finds the path environment variable
 * @env: environment variables array of strings
 *
 * Return: PATH
 */
char *get_PATH(char **env)
{
	const char *del;
	char *tok;
	int i;

	i = 0, del = "=";
	while (env[i])
	{
		tok = _strtok(env[i], del);
		if (!_strcmp("PATH", tok))
			break;
		i++;
	}
	if (env[i])
		tok = _strtok(NULL, del);
	else
		tok = NULL;
	return (tok);
}

/**
 * get_command - get full path of a command if it exists
 * @command: command name
 * @path: directories of PATH environment variable
 * Description: search every directory listed in the PATH variable
 * for the given command (if it exists and if it's not a full path)
 *
 * Return: command
 */
char *get_command(char *command, char *path)
{
	const char *del = ":";
	char *tok, *cmd;

	if (!command || !path)
		perror("empty arg to get_command()"), exit(1);

	tok = _strtok(path, del);
	while (tok)
	{
		cmd = is_path(tok, command);
		if (cmd)
			return (cmd);
		tok = _strtok(NULL, del);
	}
	return (NULL);
}

/**
 * is_path - check if a the given path exists or not
 * @dir: given directory
 * @exec: given executable
 *
 * Return: the full path combined | NULL
 */
char *is_path(char *dir, char *exec)
{
	char *buffer;
	int i, j, size;

	if (!dir || !exec)
		perror("empty arg to is_path()"), exit(1);

	size = _strlen(dir) + _strlen(exec) + 2;
	buffer = malloc(sizeof(char) * size);
	if (!buffer)
		perror("Can't allocate memory for buffer"), exit(1);

	for (i = 0; dir[i]; i++)
		buffer[i] = dir[i];
	buffer[i++] = '/';
	for (j = 0; exec[j]; j++)
		buffer[i++] = exec[j];
	for (; i < size; i++)
		buffer[i] = '\0';

	if (access(buffer, F_OK & X_OK) == -1)
		free(buffer), buffer = NULL;

	return (buffer);
}
