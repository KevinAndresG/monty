#include "monty.h"
/**
* push_function - Push a element to the stack
* @head: head of the data structure
* Return: Noting.
*/
void push_function(stack_t **stack, unsigned int line_num)
{
	int in, i = 0;

	if (!globa.arg)
	{
		dprintf(2, "L%u: ", line_num);
		dprintf(2, "usage: push integer\n");
		exit(EXIT_FAILURE);
	}
	for (; globa.arg[i] != '\0'; i++)
	{
		if (!isdigit(globa.arg[i]))
		{
			dprintf(2, "L%u:", line_num);
			dprintf(2, "usage: push integer \n");
			exit(EXIT_FAILURE);
		}
	}

	in = atoi(globa.arg);

	if (globa.st_q == 1)
	{
		add_start(stack, in);
	}
	else
	{
		add_end(stack, in);
	}

}
/**
 * pop_function - remove a element from a stack
 * @stack: header node
 * @line_number: the line that be executed
 * Return: nothing
 */
/*void pop_function(stack_t **stack, unsigned int line_number)*/
/**
 * pint_function - add to the top to a stack
 * @stack: header node
 * @line_number: the line that be executed
 * Return: nothing
 */
/*void pint_function(stack_t **stack, unsigned int line_number)*/
/**
 * pall_function - print the element
 * @stack: header node
 * @line_number: the line that be executed
 */
void pall_function(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = NULL;
	(void)line_number;

	aux = *stack;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}


}
/**
 * swap_function - swap the elements from a file
 * @stack: header node
 * @line_number: the line that be executed
 *
/*void swap_function(stack_t **stack, unsigned int line_number)*/
