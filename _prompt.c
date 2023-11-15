#include "shell.h"

/**
 * prompt - displays a shell command prompt.
 * Return: nothing.
*/
void prompt(void)
{
	write(1, "$ ", 2);
}
