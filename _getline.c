#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _getline - read string of text we have.
 * @ln_ptr: dynamically allocated bufferr.
 * @n: number of characters in the linee.
 * @strm: the file to read fromm.
 * Return: nbr of characters read
 * and stored in the buffer.
 */
ssize_t _getline(char **ln_ptr, size_t *nl, FILE *strm)
{
	size_t init_size;
	size_t total_chars = 0;
	int c;

	init_size = 32;
	if (ln_ptr == NULL || nl == NULL || strm == NULL)
		return (-1);

	if (*ln_ptr == NULL || *nl == 0)
	{
		*ln_ptr = (char *)malloc(init_size);
		if (*ln_ptr == NULL)
			return (-1);
		*nl = init_size;
	}

	while ((c = fgetc(strm)) != EOF)
	{
		if (total_chars >= *nl - 1)
		{
			size_t new_size = *nl * 2;
			char *new_lineptr = (char *)realloc(*ln_ptr, new_size);

			if (new_lineptr == NULL)
				return (-1);
			*ln_ptr = new_lineptr;
			*nl = new_size;
		}
		(*ln_ptr)[total_chars++] = c;

		if (c == '\n')
			break;
	}

	(*ln_ptr)[total_chars] = '\0';
	return (total_chars);
}

