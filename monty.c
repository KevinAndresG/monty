#include "monty.h"

Global_t globa;

/* Funcion strcmp */
/**
 * _strcmp - compares two strings.
 * @s1: string
 * @s2: string
 *
 * Return: valor.
 */
int _strcmp(char *s1, char *s2)
{
	int valor = 0;

	if (s1 < s2)
	{
		valor = -1;
	}
	else if (s1 > s2)
	{
		valor = 1;
	}
	else
	{
		valor = 0;
	}
	return (valor);
}
/* Funcion para encontar un caracter en la cadena */
int find_c(char *s, char c)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			break;
		}
		i++;
	}
	if (s[i] == c)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/* funcion especial para tokenizar */
char *_strtok(char *s, char *d)
{
	static char *last = NULL;
	int i = 0, j = 0;
	if (!s)
	{
		s = last;
	}
	while (s[i] != '\0')
	{
		if (find_c(d, s[i]) == 0 && s[i + 1] == '\0')
		{
			last = s + i + 1;
			*last = '\0';
			s = s + j;
			return s;
		}
		else if (find_c(d, s[i]) == 0 && find_c(d, s[i + 1]) == 0)
		{
			i++;
		}
		else if (find_c(d, s[i]) == 0 && find_c(d, s[i + 1]) == 1)
		{
			last = s + i + 1;
			*last = '\0';
			last++;
			s = s + j;
			return s;
		}
		else if (find_c(d, s[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return NULL;
}


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
	return file_descr;
}
int main(int argc, char **argv)
{

	/*if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	stack_t *head = NULL;
	get_file(argv[1], &head);
	exit(EXIT_SUCCESS);*/

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
		line[0] = _strtok(globa.buffer, " \t\n");
		if (line[0] && line[0][0] != '#')
		{
			f = get_functions(line[0]);

			if (!f)
			{
				dprintf(2, "L%u:", globa.actual_li);
				dprintf(2, "Unknow is ooooooo %s\n", line[0]);
				fclose(globa.file_descr);
				exit(EXIT_FAILURE);
			}
			globa.arg = _strtok(NULL, " \t\n");
			f(&globa.head, globa.actual_li);	
		}
		lines_get = getline(&globa.buffer, &size, file_descr);
		globa.actual_li++;	
	}
	

	return 0;
}
