#include "monty.h"

Global_t globa;

/* Funcion para inicializar las variables globales. */
/**
* init_vgobal - initialice the global variables
* @file_descr: file
* Return: nothing
*/
void init_vgobal(FILE *file_descr)
{
	globa.st_q = 1;
	globa.actual_li = 1;
	globa.arg = NULL;
	globa.head = NULL;
	globa.file_descr = file_descr;
	globa.buffer = NULL;
}
/* FUNCION QUE VERIFICA LA ENTRADA */
/**
*process_intro - verify if the file exist and can
* be open
* @argc: count the arguments
* @argv: the list that contain each argument
* Return: the file struct
*/
FILE *process_intro(int argc, char **argv)
{
	FILE *file_descr;

	if (argc  == 1 || argc > 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_descr = fopen(argv[1], "r");

	if (file_descr == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (file_descr);
}
/**
* main - main function
* @argc: count the arguments
* @argv: the list that contain each argument
* Return: return 0 in succes
*/
int main(int argc, char **argv)
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *file_descr;
	size_t size = 256;
	ssize_t lines_get = 0;
	char *line[2] = {NULL, NULL};

	file_descr = process_intro(argc, argv);
	init_vgobal(file_descr);

	lines_get = getline(&globa.buffer, &size, file_descr);

	while (lines_get != -1)
	{
		line[0] = _strtok(globa.buffer, DELIMS);
		if (line[0] && line[0][0] != '#')
		{
			f = get_functions(line[0]);
			if (!f)
			{
				dprintf(2, "L%u: unknown instruction %s\n", globa.actual_li, line[0]);
				/* dprintf(2, "unknown instruction %s\n", line[0]); */
				exit(EXIT_FAILURE);
			}
			globa.arg = _strtok(NULL, DELIMS);
			f(&globa.head, globa.actual_li);
		}
		lines_get = getline(&globa.buffer, &size, file_descr);
		globa.actual_li++;
	}

	return (0);
}
