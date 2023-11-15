#include "shell.h"

/**
 * free_node - releasesing memories locations carry by arg node.
 *
 * @argv: pointer to pointer to a node to frees.
 *
 * Return: void;
 *
 */

void free_node(create_cmd **argv)
{
	size_t index = 1;

	free((*argv)->command);
	while ((*argv)->argument[index] != NULL)
	{
		free((*argv)->argument[index]);
		index++;
	}
	free((*argv)->argument);

	free(*argv);
	*argv = NULL;
}
