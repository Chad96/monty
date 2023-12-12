#include "monty.h"
#include <string.h>

void free_custom_stack(stack_t **custom_stack);
int initialize_custom_stack(stack_t **custom_stack);
int check_custom_mode(stack_t *custom_stack);

/**
 * free_custom_stack - Frees a stack_t custom_stack.
 * @custom_stack: A pointer to the top (stack) or
 *                bottom (queue) of a stack_t.
 */
void free_custom_stack(stack_t **custom_stack)
{
	stack_t *tmp = *custom_stack;

	while (*custom_stack)
	{
		tmp = (*custom_stack)->next;
		free(*custom_stack);
		*custom_stack = tmp;
	}
}

/**
 * initialize_custom_stack - Initializes a stack_t custom_stack with beginning
 *                           stack and ending queue nodes.
 * @custom_stack: A pointer to an uninitialized stack_t custom_stack.
 *
 * Return: If an error occurs - EXIT_FAILURE.
 *         Otherwise - EXIT_SUCCESS.
 */
int initialize_custom_stack(stack_t **custom_stack)
{
	stack_t *cs;

	cs = malloc(sizeof(stack_t));
	if (cs == NULL)
		return (malloc_error());

	cs->n = STACK;
	cs->prev = NULL;
	cs->next = NULL;

	*custom_stack = cs;

	return (EXIT_SUCCESS);
}

/**
 * check_custom_mode - Checks if a stack_t linked list
 * @custom_stack: A pointer to the top (stack) or bottom (queue)
 *                of a stack_t linked list.
 *
 * Return: If the stack_t is in stack mode - STACK (0).
 *         If the stack_t is in queue mode - QUEUE (1).
 *         Otherwise - 2.
 */
int check_custom_mode(stack_t *custom_stack)
{
	if (custom_stack->n == STACK)
		return (STACK);
	else if (custom_stack->n == QUEUE)
		return (QUEUE);
	return (2);
}

