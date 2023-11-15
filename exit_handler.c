#include "shell.h"

/**
 * _exit_process - terminates the proceuss of the shell command.
 *
 * @status: exit status of number.
 *
 * Return: nothing.
*/

void _exit_process(char *status)
{
	if (status != NULL)
	{
		exit(_atoi(status));
	}
	else
	{
		exit(EXIT_SUCCESS);
	}
}

