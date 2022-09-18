#include "main.h"

/**
 * _copy - makes copy of a string
 * @s: given string
 *
 * Return: copy
 */
char *_copy(char *s)
{
	char *new_s;
	unsigned int i;

	if (!s)
		return (NULL);

	new_s = malloc(sizeof(char) * (_strlen(s) + 1));
	if (!new_s)
		perror("Can't allocate memory for new_s"), exit(1);
	for (i = 0; s[i]; i++)
		new_s[i] = s[i];
	new_s[i] = '\0';
	return (new_s);
}
