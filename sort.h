#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#define UP 0
#define DOWN 1

/**
* enum bool - Its Enumerates of boolean values
*/

typedef enum bool
{
false = 0,
true
} bool;


/**
* struct listint_s -  Its the Doubly linked list node
*
* @n:  The Integer stored in the node
* @prev:  The Pointer to the previous element of the list
* @next:  it's Pointer to the next element of the list
*/
typedef struct listint_s
{
const int n;
struct listint_s *prev;
struct listint_s *next;
} listint_t;

/* For Helper for swapping*/
void swap_ints(int *a, int *b);

/* Its Printing helper functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* its Regular functions prototypes*/
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

#endif
