#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 * @list: list of integers
 * Description: sorts a doubly linked list of integers in ascending order using
 * the Insertion sort algorithm
 * Don't modify the integer n of a node. You have to swap the nodes themselves.
 * You’re expected to print the list after each time you swap two elements
 *
 * Return: Nothing
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *node2;

	if (list == NULL)
		return;
	current = *list;
	while (current->next)
	{
		node2 = current->next;
		if (current->n > node2->n)
		{
			if (node2->next == NULL)
				current->next = NULL;
			else
			{
				current->next = node2->next;
				node2->next->prev = node2->prev;
				node2->next = NULL, node2->prev = NULL;
			}
			if (current->prev == NULL)
			{
				node2->next = current;
				current->prev = node2;
				*list = node2;
				print_list(*list);
				continue;
			}
			else
			{
				node2->next = current;
				node2->prev = current->prev;
				current->prev->next = node2;
				current->prev = node2;
				print_list(*list);
			}
			if (node2->n < node2->prev->n)
				insertion_sort_list(list);
			continue;
		}
		current = current->next;
	}
}
