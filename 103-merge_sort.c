#include "sort.h"

/**
 * merge_subarr - Merge two sorted subarrays into a single sorted subarray.
 * @subarr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted subarray.
 * @front: The front index of the array.
 * @mid: The middle index of the array.
 * @back: The back index of the array.
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid, size_t back)
{
    /* Function to merge two sorted subarrays into a single sorted subarray */
    size_t i, j, k = 0;

    printf("Merging...\n[left]: ");
    print_array(subarr + front, mid - front);

    printf("[right]: ");
    print_array(subarr + mid, back - mid);

    for (i = front, j = mid; i < mid && j < back; k++)
        buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
    for (; i < mid; i++)
        buff[k++] = subarr[i];
    for (; j < back; j++)
        buff[k++] = subarr[j];
    for (i = front, k = 0; i < back; i++)
        subarr[i] = buff[k++];

    printf("[Done]: ");
    print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @subarr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted result.
 * @front: The front index of the subarray.
 * @back: The back index of the subarray.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
    /* Function to implement the merge sort algorithm through recursion */
    size_t mid;

    if (back - front > 1)
    {
        mid = front + (back - front) / 2;
        merge_sort_recursive(subarr, buff, front, mid);
        merge_sort_recursive(subarr, buff, mid, back);
        merge_subarr(subarr, buff, front, mid, back);
    }
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
    /* Function to perform merge sort on the array */
    int *buff;

    if (array == NULL || size < 2)
        return;

    buff = malloc(sizeof(int) * size);
    if (buff == NULL)
        return;

    merge_sort_recursive(array, buff, 0, size);

    free(buff);
}

