#include "shell.h"

/**
 * _ctrlC - handles the user interrupt signals.
 *
 * @sig: unusedes.
 *
 * Return: void.
*/

void _ctrlC(int sig __attribute__((unused)))
{
	_putchar('\n');
	prompt();
}

