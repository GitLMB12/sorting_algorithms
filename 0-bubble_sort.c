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
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */

void bubble_sort(int *array, size_t size)
{
	int i, j;
	int n = size;

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_f(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
