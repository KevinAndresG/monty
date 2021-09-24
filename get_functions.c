#include "monty.h"
/**
 * get_functions - Get the functions from the file
 * @stack: pointer to be added
 * @tok: the exactly string to be searched as function
 * @line_number: the line that be executed
 * Return: nothing
 */
void (*get_functions(char *tok))(stack_t **stack, unsigned int line_number)
{
	int run = 0;

	instruction_t all_ops[] = {
		{"push", push_function},
		{"pall", pall_function},
		/**
		* {"pint", pint_function},
		* {"pop", pop_function},
		* {"swap", swap_function},
		* {"add", add_function},
		* {"nop", nop_function},
		*/
		{NULL, NULL}
	};

	for (; all_ops[run].opcode; run++)
	{
		if (_strcmp(tok, all_ops[run].opcode) == 0)
		{
			break;
		}
	}
	return (all_ops[run].f);
}
