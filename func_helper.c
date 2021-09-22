#include "monty.h"
/**
 * Get_file - obtain the content of the file specified
 * @received_file: the file to be readed
 * @head: the head node
 * Return: an int
 */
int get_file(char *received_file, stack_t **head)
{
	char *line;
	size_t line_size;
	ssize_t save;
	unsigned int line_number = 0;
	char *tok;
	FILE fd;

	if (!file)
	{
		printf("Error: Can't open file %s\n", received_file);
		exit(EXIT_FAILURE);
	}

	fd = fopen(received_file, "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((save = getline(&line, &line_size, fd)) != -1)
	{
		printf("%s", save);
		tok = strtok(line, " \n,\t");
		line_number++;
		if (tok)
		{
			get_functions(head, tok, line_number);
		}
	}
	fclose(fd);
	free(line);
	return (EXIT_SUCCESS);
}
