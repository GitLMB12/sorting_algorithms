#include "sort.h"

/**
 * move_left - Helper function to swap two adjacent nodes in a linked list.
 * @curr: Current node.
 * @prev: Previous node.
 * @head: Pointer to the head of the list.
 */
void move_left(listint_t *curr, listint_t *prev, listint_t **head)
{
	listint_t *next_node = curr->next;
	listint_t *prev_node = prev->prev;
	if (next_node != NULL)
		next_node->prev = prev;
	if (prev_node != NULL)
		prev_node->next = curr;
	curr->prev = prev_node;
	prev->next = next_node;
	curr->next = prev;
	prev->prev = curr;
	if (*head == prev)
		*head = curr;
	print_list(*head);
}
/**
 * cocktail_sort_list - Sorts a doubly linked list using the Cocktail Shaker Sort algorithm.
 * @list: Pointer to a pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *max = NULL;
	listint_t *min = NULL;
	if (!list || !(*list) || (*list)->next == NULL)
		return;
	current = *list;
    
	do {
		while (current->next)
		{
			if (current->n > current->next->n)
				move_left(current->next, current, list);
			else
				current = current->next;
		}
		max = current;
		while (current->prev != min)
		{
			if (current->n < current->prev->n)
				move_left(current, current->prev, list);
			else 
				current = current->prev;
		}
		min = current;
	}
	while (min != max);
}
