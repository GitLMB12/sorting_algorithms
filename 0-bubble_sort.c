#include "sort.h"
#include <stdbool.h>
/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */

void bubble_sort(int *array, size_t size)
{
	int temp;
	bool flag = true;
	unsigned int i, j;
	size_t n = size;

	for (i = 0; i < n - 1; i++)
	{
		flag = false;
		for (j = 0; j < n - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				flag = true;
			}
		}
		if (!flag)
		{
			break;
		}
	}
}
