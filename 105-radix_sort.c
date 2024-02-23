#include "sort.h"

/**
 * pow_10 - Calculates a positive power of 10.
 * @power: Power of 10 to calculate.
 * Return: Final result.
 */
unsigned int pow_10(unsigned int power)
{
	unsigned int res = 1;
	for (unsigned int i = 0; i < power; i++)
		res *= 10;
	return res;
}
/**
 * count_sort - Sorts an array of integers in ascending order.
 * @array: Array to be sorted.
 * @size: Size of the array to be sorted.
 * @digit: Digit to sort.
 * Return: 1 if further sorting is needed, otherwise 0.
 */
unsigned int count_sort(int *array, size_t size, unsigned int digit)
{
	int count[10] = {0};
	int *cpy = malloc(sizeof(int) * size);

	if (cpy == NULL)
		return (0);
	unsigned int dp1 = pow_10(digit), dp2 = dp1 / 10, sort = 0;
	size_t j;

	for (j = 0; j < size; j++)
	{
		cpy[j] = array[j];
		if (array[j] / dp1 != 0)
			sort = 1;
	}
	size_t j;
	for (j = 0; j < size; j++)
        count[(array[j] % dp1) / dp2]++;
	size_t j;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	size_t j;

	for (j = size - 1; j >= 0; j--)
	{
		array[--count[(cpy[j] % dp1) / dp2]] = cpy[j];
	}
	free(cpy);
	return (sort);
}
/**
 * radix_sort - Radix sort algorithm.
 * @array: Array to sort.
 * @size: Size of the array.
 */
void radix_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	unsigned int sort = 1;
	unsigned int digit;

	for (digit = 1; sort == 1; digit++)
	{
		sort = count_sort(array, size, digit);
		print_array(array, size);
	}
}
