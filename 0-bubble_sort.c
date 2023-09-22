#include "sort.h"

/**
 * bubble_sort - functionto sort an array of integer in an ascending order
 * @array: array of int
 * @size: The size of the arry
 * Return: 0
 */


void bubble_sort(int *array, size_t size)
{
	size_t temp, size_a, flag;
	size_t a, b;

	size_a = size - 1;




	for (a = 0; a < size; a++)
	{
		flag = 0;
		for (b = 0; b < size_a; b++)
		{
			if (array[b + 1] < array[b])
			{
				temp = array[b];
				array[b] = array[b + 1];
				array[b + 1] = temp;
				print_array(array, size);
			}
			else
			{
				if (flag++ == size_a)
				{
					return;
				}
			}
		}
	}

}
