#include "monty.h"

Global_t globa;

/* Funcion para inicializar las variables globales. */

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
FILE *process_intro(int argc, char **argv)
{
	FILE *file_descr;
	
	if (argc  == 1 || argc > 2)
	{
		dprintf(2, "Usasge: monty\n");
		exit(EXIT_FAILURE);
	}

	file_descr = fopen(argv[1], "r");
	
	if (file_descr == NULL)
	{
		dprintf(2, "Error: cannot open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (file_descr);
}
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
	printf("%s\n", globa.buffer);

	while (lines_get != -1)
	{
		line[0] = _strtok(globa.buffer, " \t\n");
		if (line[0] && line[0][0] != '#')
		{
			f = get_functions(line[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", globa.actual_li);
				dprintf(2, "unknown instruction %s\n", line[0]);
				exit(EXIT_FAILURE);
			}
			globa.arg = _strtok(NULL, " \t\n");
			f(&globa.head, globa.actual_li);
		}
		lines_get = getline(&globa.buffer, &size, file_descr);
		globa.actual_li++;
	}

	/*fclose(globa.file_descr);*/

	return (0);
}
