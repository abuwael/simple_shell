#include "shell.h"

/**
 * func_ptr - its look any funtion matchings string.
 *
 * @str: inputs strings to looks for.
 *
 * Return:the pointers to a functions that taking a string
 *
 * argv as input and returns void
 *
*/

void (*func_ptr(char *str))(char *)
{
	int i = 0;

	built_in cmd[] = {
		{"exit", _exit_process},
		{"env", env},
		{NULL, NULL}
	};

	while (cmd[i].cmdname != NULL)
	{
		if (_strcmp(cmd[i].cmdname, str) == 0)
		{
			return (cmd[i].function);
		}
		i++;
	}
	return (NULL);
}
