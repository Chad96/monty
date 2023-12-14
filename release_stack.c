#include "monty.h"
/**
* release_stack - sets a doubly linked list free
* @head: head of the stack
*/
void release_stack(stack_t *head)
{
	stack_t *aux;

	aux = head;
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}
