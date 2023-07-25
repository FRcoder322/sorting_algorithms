#include "deck.h"

/**
 * _strcmp - Compares two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 *
 * Return: Positive byte difference if s1 > s2
 *         0 if s1 == s2
 *         Negative byte difference if s1 < s2
 */
int _strcmp(const char *s1, const char *s2)
{
    /* Function to compare two strings */
    while (*s1 && *s2 && *s1 == *s2)
    {
        s1++;
        s2++;
    }

    if (*s1 != *s2)
        return (*s1 - *s2);
    return (0);
}

/**
 * get_value - Get the numerical value of a card.
 * @card: A pointer to a deck_node_t card.
 *
 * Return: The numerical value of the card.
 */
char get_value(deck_node_t *card)
{
    /* Function to get the numerical value of a card */
    if (_strcmp(card->card->value, "Ace") == 0)
        return (0);
    // Values 1 to 10 are represented as their corresponding numbers
    // "Jack" is represented as 11
    // "Queen" is represented as 12
    return (13); // "King" is represented as 13
}

/**
 * insertion_sort_deck_kind - Sort a deck of cards from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_kind(deck_node_t **deck)
{
    /* Function to perform insertion sort on the deck based on card kinds */
    deck_node_t *iter, *insert, *tmp;

    for (iter = (*deck)->next; iter != NULL; iter = tmp)
    {
        tmp = iter->next;
        insert = iter->prev;
        while (insert != NULL && insert->card->kind > iter->card->kind)
        {
            // Swap the nodes to perform the insertion
            // Sorting based on card kinds (spades to diamonds)
            insert->next = iter->next;
            if (iter->next != NULL)
                iter->next->prev = insert;
            iter->prev = insert->prev;
            iter->next = insert;
            if (insert->prev != NULL)
                insert->prev->next = iter;
            else
                *deck = iter;
            insert->prev = iter;
            insert = iter->prev;
        }
    }
}

/**
 * insertion_sort_deck_value - Sort a deck of cards sorted from
 *                             spades to diamonds from ace to king.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_value(deck_node_t **deck)
{
    /* Function to perform insertion sort on the deck based on card values */
    deck_node_t *iter, *insert, *tmp;

    for (iter = (*deck)->next; iter != NULL; iter = tmp)
    {
        tmp = iter->next;
        insert = iter->prev;
        while (insert != NULL &&
               insert->card->kind == iter->card->kind &&
               get_value(insert) > get_value(iter))
        {
            // Swap the nodes to perform the insertion
            // Sorting based on card values within the same kind
            insert->next = iter->next;
            if (iter->next != NULL)
                iter->next->prev = insert;
            iter->prev = insert->prev;
            iter->next = insert;
            if (insert->prev != NULL)
                insert->prev->next = iter;
            else
                *deck = iter;
            insert->prev = iter;
            insert = iter->prev;
        }
    }
}

/**
 * sort_deck - Sort a deck of cards from ace to king and
 *             from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
    /* Function to sort the deck of cards */
    if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
        return;

    // Sort the deck first based on card kinds (spades to diamonds)
    insertion_sort_deck_kind(deck);
    // Then sort the deck based on card values within the same kind
    insertion_sort_deck_value(deck);
}

