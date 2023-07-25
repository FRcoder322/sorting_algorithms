#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Its Swap two integers in an array.
 * @a: TIts first integer to swap.
 * @b: Its second integer to swap.
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Order a subset of an array of integers 

 * @size: size of the array.
 * @left: its starting index of the subset to order.
 * @right:  Its The ending index of the subset to order.
 * @array: its  array of integers.

 *
 * Return: The final partition index.
 */

int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort -  its Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.

 * @right: Its  ending index of the array partition to order.
 * @size: its size of the array.
 * @left: its starting index of the array partition to order.
 * Description:  its Uses the Lomuto partition scheme.
 */

void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort -  its Sort an array of integers in ascending
 * @array: its array of integers.
 * @size: its  size of the array.
 * Description: Uses the Lomuto partition scheme. 
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
