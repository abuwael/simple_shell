#include "shell.h"

/**
  * _puts2 - that fun print string and print anew line
  *
  * @c: pointer to strings of characters
  *
  * Return: Void
*/

void _puts2(char *c)
{
	write(STDOUT_FILENO, c, _strlen(c));
}

/**
  * print_error - Displaying massege Error Based on Command shell
  *
  * @input:User Inputs
  *
  * @counter:Simples command Shells Counts Looped
  *
  * @argv:Program Names
  *
  * Return: Void
  */

void print_error(char *input, int counter, char *argv)
{
	char *er;

	_puts2(argv);
	_puts2(": ");
	er = _itoa(counter);
	_puts2(er);
	free(er);
	_puts2(": ");
	_puts2(input);
	_puts2(": not found\n");
}
