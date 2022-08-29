#include "main.h"

/**
 * free_2D - frees 2 dimensional array
 * @arr: array to be freed
 *
 * Return: void
 */
void free_2D(char **arr)
{
	unsigned int i;

	if (!arr)
		return;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	arr = NULL;
}

/**
 * _strlen - finds length of a string
 * @s: string given
 * Return: length
 */
int _strlen(char *s)
{
	int size, i;

	i = 0;
	size = 0;
	while (s[i++] != '\0')
		size++;

	return (size);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: integer less than or equal or greater than 0
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] - s2[i] != 0)
			return (s1[i] - s2[i]);
		i++;
	}

	if (s1[i] != '\0')
		return (s1[i]);
	else if (s2[i] != '\0')
		return (s2[i]);


	return (0);
}

/**
 * _strcpy - copies string from source to destination
 * @dest: destination
 * @src: source
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];

	return (dest);
}
