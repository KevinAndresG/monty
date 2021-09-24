#include "monty.h"

/**
* add_start - add node at the start
* @head: the head node
* @n: the node to insert
* Return: a structure
*/
stack_t *add_start(stack_t **head, const int n)
{
	stack_t *aux = NULL;

	if (head == NULL)
	{
		return (NULL);
	}
	aux = malloc(sizeof(stack_t));
	if (!aux)
	{
		dprintf(2, "Error: malloc failed \n");
		free_all();
		exit(EXIT_FAILURE);
	}
	aux->n = n;

	if (*head == NULL)
	{
		aux->next = *head;
		aux->prev = NULL;
		*head = aux;
		return (*head);
	}
	(*head)->prev = aux;
	aux->next = (*head);
	aux->prev = NULL;
	*head = aux;

	return (*head);
}

/**
* add_end - add node at end
* @head: the head node
* @n: the node to insert
* Return: a structure
*/
stack_t *add_end(stack_t **head, const int n)
{
	stack_t *aux = NULL, *temp = NULL;

	if (head == NULL)
	{
		return (NULL);
	}
	aux = malloc(sizeof(stack_t));

	if (!aux)
	{
		dprintf(2, "Error: malloc() failed\n");
		free_all();
		exit(EXIT_FAILURE);
	}
	aux->n = n;

	if (*head == NULL)
	{
		aux->next = *head;
		aux->prev = NULL;
		*head = aux;
		return (*head);
	}

	temp = *head;

	while (temp->next)
	{
		temp = temp->next;
	}
	aux->next = temp->next;
	aux->prev = temp;
	temp->prev = aux;

	return (temp->next);
}

