#include "monty.h"

/**
 * free_list - frees the doubly linked list
 *
 * @head: head of the list
 * Return: no return
 */
void free_list(stack_t *head)
{
	stack_t *aux;

	while ((aux = head) != NULL)
	{
		head = head->next;
		free(aux);
	}
}

/**
 * free_all - frees the global variables
 *
 * Return: no return
 */
void free_all(void)
{
	free_list(globa.head);
	free(globa.buffer);
	fclose(globa.file_descr);
}
