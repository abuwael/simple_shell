#include "shell.h"

/**
 * _strncpy - copy n byte of the string.
 *
 * @dest: pointer to the string destinations.
 *
 * @src: pointer to strings sources.
 *
 * @n: numbers of bytes to copy.
 *
 * Return: pointer to the destination string.
*/

char *_strncpy(char *dest, char *src, int n)
{
	int j = 0;

	for (j = 0; src[j] != '\0'; j++)
	{
		if (j < n)
		{
			dest[j] = src[j];
		}
	}

	for (; j < n; j++)
	{
		dest[j] = '\0';
	}

	return (dest);
}

/**
 * _strstr - found the first occurrence of the substr in the main strings.
 *
 * @mainstr: pointers to the main string.
 *
 * @substr: pointers to substr
 *
 * Return: a pointer to the beginning of the located substr,
 *
 * or NULL if the substring is not found.
*/

char *_strstr(char *mainstr, char *substr)
{
	int i = 0, j = 0;

	if (!*substr)
	{
		return (mainstr);
	}

	while (mainstr[i])
	{
		while (substr[j] && mainstr[i + j] == substr[j])
		{
			j++;
		}
		if (!substr[j])
		{
			return (mainstr + i);
		}
		i++;
		j = 0;
	}
	return (NULL);
}

/**
 * _strcpy - coping the string from sources to destinations
 *
 * @destination: where the strings is copies to
 *
 * @source: where the strings is copies
 *
 * Return: pointer to the destinations
 *
*/

char *_strcpy(char *destination, char *source)
{

	while (*source != '\0')
	{
		*destination++ = *source++;
	}
	*destination = '\0';

	return (destination);
}

/**
 * _puts - fun print string and print new line
 *
 * @str: pointer to strings of character
 *
 * Return: Void
*/

void _puts(char *str)
{
	char try;

	do {
		if (*str != '\0')
		{
			try = *str;
			_putchar(try);
		}
	} while (*str++);
	_putchar('\n');
}

/**
 * _putchar - writes the characters c to stdout
 *
 * @c: The characters to prints
 *
 * Return: On success 1.
 *
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
