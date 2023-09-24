#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 * @list: list of integers
 *
 * Description: Sorts a doubly linked list of integers in ascending order using
 * the Insertion sort algorithm. Does not modify the integer n of a node.
 * Swaps the nodes themselves. Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *nextNode;

	if (list == NULL || *list == NULL)
		return;

	current = *list;
	while (current->next)
	{
	nextNode = current->next;
	if (current->n > nextNode->n)
	{
		if (nextNode->next == NULL)
			current->next = NULL
		else
		{
		current->next = nextNode->next;
		nextNode->next->prev = nextNode->prev;
		nextNode->next = NULL;
		nextNode->prev = NULL;
		}
		if (current->prev == NULL)
		{
		nextNode->next = current;
		current->prev = nextNode;
		*list = nextNode;
		}
		else
		{
		nextNode->next = current;
		nextNode->prev = current->prev;
		current->prev->next = nextNode;
		current->prev = nextNode;
		}
		print_list(*list);
		if (nextNode->n < nextNode->prev->n)
		insertion_sort_list(list);
	}
	else
		current = current->next;
	}
}
