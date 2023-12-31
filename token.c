#include "shell.h"

/**
 * break_input_line - the breaking is the input the lines and creating tokens.
 *
 * @line: pointer to the line of af str to break.
 *
 * @separator: pointer to the tokens separator.
 *
 * Return: arrays of individuals words from an input new line.
*/

char *break_input_line(char *line, char *separator)
{
	static char *input_line = NULL, words_array[64][20];
	static int word_count;
	char *ptr_start, *ptr_end;
	int len;

	if (line != NULL)
	{
		input_line = line;
		word_count = 0;
	}

	if (input_line == NULL)
		return (NULL);

	ptr_start = input_line;
	ptr_end = _strstr(input_line, separator);

	if (ptr_end == NULL)
		ptr_end = input_line + _strlen(input_line);

	len = ptr_end - ptr_start;
	_strncpy(words_array[word_count], ptr_start, len);
	words_array[word_count][len] = '\0';
	word_count++;

	if (word_count == 64)
		return (NULL);

	if (*ptr_end == '\0')
		input_line = NULL;
	else
		input_line = ptr_end + _strlen(separator);

	return (words_array[word_count - 1]);
}
