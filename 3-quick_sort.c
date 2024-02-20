#include "sort.h"

/**
 * swap_f - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_f(int *a, int *b)
{
	int change = *a;
	*a = *b;
	*b = change;
}
/**
 * partition - array partition
 * @array: array to sort
 * @low: first position
 * @high: last position
 * @size: array size
 * Return: int pivot index
 */
int partition(int array[], int low, int high, size_t size)
{
	int pivot = array[high];
	int j = low - 1;
	int i;

	for (i = low ; i <= high; i++)
	{
		if (array[i] < pivot)
		{
			j++;
			swap_f(&array[i], &array[j]);
		}
	}
	swap_f(&array[j + 1], &array[high]);
	print_array(array, size);
	return (j + 1);
}
/**
 * quick_sort_helper - sorts an array of integers recursively
 * @array: array to sort
 * @low: first position
 * @high: last position
 * @size: array size
 */
void quick_sort_helper(int array[], int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = partition(array, low, high, size);

		quick_sort_helper(array, low, pi - 1, size);
		quick_sort_helper(array, pi + 1, high, size);
	}
}
/**
 * quick_sort - sorts an array of integers using the Quick
 * sort algorithm in ascending order
 * @array: array to sort
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_helper(array, 0, size - 1, size);
}
