#include "sort.h"

/**
 * quick_sort - Sorts an array of integers using the quicksort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: The number of elements in the array.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	/* Call the recursive sorting function */
	my_recursive_quick_sort(array, 0, size - 1, size);
}

/**
 * swap - Swaps two integer values.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Partitions an array and returns the pivot index.
 * @array: Pointer to the array to be partitioned.
 * @left: The leftmost index of the partition.
 * @right: The rightmost index of the partition.
 * @size: The size of the array.
 *
 * Return: The index of the pivot element.
 */
int lomuto_partition(int *array, int left, int right, size_t size)
{
	int pivot, idx, j;

	pivot = array[right];
	idx = left;

	for (j = left; j < right; j++)
	{
		if (array[j] < pivot)
		{
			if (idx != j && array[idx] != array[right])
			{
				swap(&array[idx], &array[j]);
				print_array(array, size);
			}
			idx++;
		}
	}

	if (idx != right && array[idx] != array[right])
	{
		swap(&array[idx], &array[right]);
		print_array(array, size);
	}

	return (idx);
}

/**
 * my_recursive_quick_sort - Recursively sorts an array using quicksort.
 * @array: Pointer to the array to be sorted.
 * @left: The leftmost index of the subarray.
 * @right: The rightmost index of the subarray.
 * @size: The size of the array.
 */
void my_recursive_quick_sort(int *array, int left, int right, size_t size)
{
	int pivot;

	if (left < right)
	{
		pivot = lomuto_partition(array, left, right, size);
		my_recursive_quick_sort(array, left, pivot - 1, size);
		my_recursive_quick_sort(array, pivot + 1, right, size);
	}
}
