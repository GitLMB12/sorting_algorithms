#include "sort.h"

/**
 * swap_f - swap two pointers to integer
 *
 * @a: first int pointer
 * @b: second int pointer
 */
void swap_f(int *a, int *b)
{
	int swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

/**
 * selection_sort - sort an array of integers using selection sort
 *
 * @array: the array to order
 * @size: the siz of the array to order
 */

void selection_sort(int *array, size_t size)
{
	int i;
	int j;
	int min;
	int n = size;

	for (i = 0; i < n; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			swap_f(&array[min], &array[i]);
			print_array(array, size);
		}
	}
}
