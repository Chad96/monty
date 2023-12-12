#include "monty.h"

void custom_rotl(stack_t **custom_stack, unsigned int custom_line_number);
void custom_rotr(stack_t **custom_stack, unsigned int custom_line_number);
void custom_stack_mode(stack_t **custom_stack,
		unsigned int custom_line_number);
void custom_queue_mode(stack_t **custom_stack,
		unsigned int custom_line_number);

/**
 * custom_rotl - Rotates the top value of a stack_t linked list
 * @custom_stack: A pointer to the top mode node
 * @custom_line_number: The current working line number
 */
void custom_rotl(stack_t **custom_stack, unsigned int custom_line_number)
{
	stack_t *custom_top, *custom_bottom;

	if ((*custom_stack)->next == NULL || (*custom_stack)->next->next == NULL)
		return;

	custom_top = (*custom_stack)->next;
	custom_bottom = (*custom_stack)->next;
	while (custom_bottom->next != NULL)
		custom_bottom = custom_bottom->next;

	custom_top->next->prev = *custom_stack;
	(*custom_stack)->next = custom_top->next;
	custom_bottom->next = custom_top;
	custom_top->next = NULL;
	custom_top->prev = custom_bottom;
	(void)custom_line_number;
}

/**
 * custom_rotr - Rotates the bottom value of a stack_t linked list to the top.
 * @custom_stack: A pointer to the top mode node of a stack_t
 * @custom_line_number: The current working line number
 */
void custom_rotr(stack_t **custom_stack, unsigned int custom_line_number)
{
	stack_t *custom_top, *custom_bottom;

	if ((*custom_stack)->next == NULL || (*custom_stack)->next->next == NULL)
		return ();

	custom_top = (*custom_stack)->next;
	custom_bottom = (*custom_stack)->next;

	while (custom_bottom->next != NULL)
		custom_bottom = custom_bottom->next;

	custom_bottom->prev->next = NULL;
	(*custom_stack)->next = custom_bottom;
	custom_bottom->prev = *custom_stack;
	custom_bottom->next = custom_top;
	custom_top->prev = custom_bottom;

	(void)custom_line_number;
}

/**
 * custom_stack_mode - Converts a queue to a stack.
 * @custom_stack: A pointer to the top mode node
 * @custom_line_number: The current working line number
 */
void custom_stack_mode(stack_t **custom_stack, unsigned int custom_line_number)
{
	(*custom_stack)->n = STACK;
	(void)custom_line_number;
}

/**
 * custom_queue_mode - Converts a stack to a queue.
 * @custom_stack: A pointer to the top mode node
 * @custom_line_number: The current working line number
 */
void custom_queue_mode(stack_t **custom_stack, unsigned int custom_line_number)
{
	(*custom_stack)->n = QUEUE;
	(void)custom_line_number;
}
