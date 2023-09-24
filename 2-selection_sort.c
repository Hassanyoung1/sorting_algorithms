#include "sort.h"

/**
 * selection_sort - Sorts an integer array in ascending order using
 *                  the selection sort algorithm.
 *
 * @array: Pointer to the integer array to be sorted.
 * @size:  Number of elements in the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t k, j;
	int temp;
	size_t lwest;

	/* Iterate through the array */
	for (k = 0; k < size - 1; k++)
	{
		/* Assume the current index 'i' contains the minimum value */
		lwest = k;

		/* Find the index of the minimum element in the unsorted part */
		for (j = k + 1; j < size; j++)
		{
			if (array[j] < array[lwest])
			{
				/* Update the 'lowest' index if a smaller element is found */
				lwest = j;
			}
		}

		/* If 'lowest' index is different from 'i', swap the elements */
		if (k != lwest)
		{
			temp = array[k];
			array[k] = array[lwest];
			array[lwest] = temp;
			/* Print the current state of the array after swapping */
			print_array(array, size);
		}
	}
}
