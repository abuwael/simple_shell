#ifndef COMMAND_H
#define COMMAND_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

extern char **environ;

/**
 * struct command - structure for built_in commands
 *
 * @cmdname: Command name to be called.
 *
 * @function: function performing the command task
 *
 * Description: The structure contains the name of a function
 * to be called and a function pointer to the function to be called.
 */

typedef struct command
{
	char *cmdname;
	void (*function)(char *arg);
} built_in;

/**
 * struct command_s - the structure store a commmand and arguments
 *
 * @command: command name or simply a command.
 *
 * @argument: Array of arguments of the command.
 *
 * @next: pointer to the next node.
 *
 * Description: Every command and the arguments are craeted as a node
 * at each command call.
 */

typedef struct command_s
{
	char *command;
	char **argument;
	struct command_s *next;
} create_cmd;



void prompts(void);

#endif
