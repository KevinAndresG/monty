#include "monty.h"
/**
* push_function - Push a element to the stack
* @stack: head of the data structure
* @line_num: number of lines
* Return: Noting.
*/
void push_function(stack_t **stack, unsigned int line_num)
{
	int in, i = 0;

	if (!globa.arg)
	{
		dprintf(2, "L%u: ", line_num);
		dprintf(2, "usage: push integer\n");
		free_all();
		exit(EXIT_FAILURE);
	}
	for (; globa.arg[i] != '\0'; i++)
	{
		if (!isdigit(globa.arg[i]))
		{
			dprintf(2, "L%u:", line_num);
			dprintf(2, "usage: push integer \n");
			free_all();
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
 * pall_function - print all the values
 * @stack: header node
 * @line_number: the line that be executed
 * Return: nothing
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
* pint_function - prints value at top of stack
 * @stack: double pointer to the first node
 * @line_number: value of new node
 * Return: nothing
 */

void pint_function(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop_function - removes top element of stack
 * @stack: double pointer to the first node
 * @line_number: value of new node
 * Return: nothing
 */
void pop_function(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	new = *stack;
	(*stack) = (*stack)->next;
	free(new);
}
