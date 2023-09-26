#include "sort.h"

/**
 * quick_sort - implements a quicksort algorithm
 * @arr: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *arr, size_t size)
{
	if (!arr || size < 2)
		return;

	my_sort_recursive(arr, 0, size - 1, size);
}

/**
 * my_swap - swaps 2 elements
 * @a: first element to swap
 * @b: second element to swap
 */
void my_swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * my_lomuto_partition - splits given array into partition then sorts
 * @arr: array to sort
 * @left: first index
 * @right: last index
 * @size: size of array
 * Return: index of the pivot element
 */
int my_lomuto_partition(int *arr, int left, int right, size_t size)
{
	int pivot, idx, j;

	pivot = arr[right];
	idx = left;

	for (j = left; j < right; j++)
	{
		if (arr[j] < pivot)
		{
			if (idx != j && arr[idx] != arr[right])
			{
				my_swap(&arr[idx], &arr[j]);
				print_array(arr, size);
			}
			idx++;
		}
	}

	if (idx != right && arr[idx] != arr[right])
	{
		my_swap(&arr[idx], &arr[right]);
		print_array(arr, size);
	}

	return (idx);
}

/**
 * my_sort_recursive - recursively sorts given algorithm
 * @arr: array to sort
 * @left: first index
 * @right: last index
 * @size: size of array
 */
void my_sort_recursive(int *arr, int left, int right, size_t size)
{
	int pivot;

	if (left < right)
	{
		pivot = my_lomuto_partition(arr, left, right, size);
		my_sort_recursive(arr, left, pivot - 1, size);
		my_sort_recursive(arr, pivot + 1, right, size);
	}
}
