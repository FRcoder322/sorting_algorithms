#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
    /* Function to find the maximum value in the array */
    int max, i;

    for (max = array[0], i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    return (max);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
    /* Function to perform counting sort on the given array */
    int *count, *sorted, max, i;

    if (array == NULL || size < 2)
        return;

    sorted = malloc(sizeof(int) * size);
    if (sorted == NULL)
        return;
    max = get_max(array, size);
    count = malloc(sizeof(int) * (max + 1));
    if (count == NULL)
    {
        free(sorted);
        return;
    }

    /* Initialize the count array */
    for (i = 0; i < (max + 1); i++)
        count[i] = 0;

    /* Count the occurrences of each element in the input array */
    for (i = 0; i < (int)size; i++)
        count[array[i]] += 1;

    /* Modify the count array to have the actual positions in the sorted array */
    for (i = 1; i < (max + 1); i++)
        count[i] += count[i - 1];

    /* Print the counting array */
    print_array(count, max + 1);

    /* Build the sorted array */
    for (i = (int)size - 1; i >= 0; i--)
    {
        sorted[count[array[i]] - 1] = array[i];
        count[array[i]] -= 1;
    }

    /* Copy the sorted array back to the input array */
    for (i = 0; i < (int)size; i++)
        array[i] = sorted[i];

    free(sorted);
    free(count);
}

