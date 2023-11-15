#include "shell.h"

/**
 * execute_path_command - Processor a given by the user.
 *
 * @argv: a pointers to a create_cmd structs as an arguments.
 *
 * @n: numbers to indicates processor creating by the shell or
 *
 * it indicates how many commands executed.
 *
 * @av: The name of the executable file.
 *
 * Return: nothing
*/

void execute_path_command(create_cmd *argv, int n, char *av)
{
	pid_t child;
	char *command = NULL;
	int status;

	command = _cmd_abs_path(argv->command);

	if (command != NULL)
	{
		if (argv->command != command)
		{
			free(argv->command);
			argv->command = command;
			argv->argument[0] = command;
		}

		child = fork();

		if (child == 0)
		{
			if (execve(argv->command, argv->argument, environ) == -1)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(child, &status, 0);
		}
	}
	else
	{
		print_error(argv->command, n, av);
	}
}

/**
 * execution_call - calling  the execution of a command.
 *
 * @av: pointers to the names of the shell file.
 *
 * Return: nothing.
 */

void execution_call(char *av)
{
	char *delim = " ";
	char ptr_line[1024];
	create_cmd *argv = NULL;
	void (*built_in_func)(char *);
	int n_byte;
	static int process_count;

	n_byte = _readline(ptr_line);
	if (n_byte == -1)
	{
		exit(0);
	}

	if (n_byte > 0)
	{
		parse_cmd(&argv, ptr_line, delim);

		built_in_func = func_ptr(argv->command);

		process_count++;
		if (built_in_func != NULL)
		{
			built_in_func(argv->argument[1]);
			free_node(&argv);
		}
		else
		{
			execute_path_command(argv, process_count, av);
			free_node(&argv);
		}
	}
}

/**
 * main - The shell's entry point and waits for user input.
 *
 * @argc: arguments counts
 *
 * @argv: arrays of shellcommand arguments.
 *
 * Return: exits with success signal unless interrupted.
 */

int main(int argc __attribute__((unused)), char **argv)
{

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			signal(SIGINT, _ctrlC);
			prompt();
		}
		execution_call(argv[0]);
	}

	exit(EXIT_SUCCESS);
}
