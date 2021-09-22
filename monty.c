#include "monty.h"
void main(int argc, char **argv)
{

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	stack_t *head = NULL;
	get_file(argv[1], &head);
	exit(EXIT_SUCCESS);
}
