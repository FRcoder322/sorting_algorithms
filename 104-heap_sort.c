#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
    /* Function to swap two integers in an array */
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * max_heapify - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
    /* Function to turn a binary tree into a complete binary heap */
    size_t left, right, large;

    left = 2 * root + 1;
    right = 2 * root + 2;
    large = root;

    if (left < base && array[left] > array[large])
        large = left;
    if (right < base && array[right] > array[large])
        large = right;

    if (large != root)
    {
        swap_ints(array + root, array + large);
        print_array(array, size);
        max_heapify(array, size, base, large);
    }
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
    /* Function to perform heap sort on the array */
    int i;

    if (array == NULL || size < 2)
        return;

    // Build a max heap by calling max_heapify for each non-leaf node in reverse order
    for (i = (size / 2) - 1; i >= 0; i--)
        max_heapify(array, size, size, i);

    // Extract elements from the heap and put them in their correct positions
    for (i = size - 1; i > 0; i--)
    {
        swap_ints(array, array + i);
        print_array(array, size);
        // Re-establish the heap property for the remaining heap
        max_heapify(array, size, i, 0);
    }
}

