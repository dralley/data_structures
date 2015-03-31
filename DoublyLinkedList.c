/**
 * Implementation of a doubly-linked list for 32-bit integers
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "LinkedList.h"

/**
 * Singly-linked implementation of the linked list node
 */
struct node_t {
    int val;
    struct node_t *next;
    struct node_t *prev;
};

/** LinkedList base struct */
struct llist_t {
    int size;
    Node *head;
    Node *tail;
};

/**
 * Return an empty LinkedList
 */
LinkedList *LinkedList_new()
{
    LinkedList *new = (LinkedList*) malloc( sizeof(LinkedList) );
    new->size = 0;
    new->head = NULL;
    new->tail = NULL;

    return new;
}

/**
 * Delete and free the linked LinkedList
 */
void LinkedList_delete( LinkedList *list )
{
    Node *entry = list->head;

    while ( entry ) {
        Node *next = entry->next;
        free( entry );
        entry = next;
    }

    free( list );
}

/**
 * Returns the size of the list
 */
int LinkedList_size( LinkedList *list )
{
    return list->size;
}

/**
 * Get integer at position [pos] in the list
 */
int LinkedList_get( LinkedList *list, int pos )
{
    assert( pos >= 0 && pos < list->size );

    Node *entry = list->head;
    for (int i=0; i<pos; i++) {
        entry = entry->next;
    }

    return entry->val;
}

/**
 * Insert integer [val] at position [pos] in the list
 */
void LinkedList_insert( LinkedList *list, int val, int pos )
{
    assert( pos >= 0 && pos <= list->size );

    Node *new = (Node*) malloc( sizeof(Node) );
    new->val = val;

    list->size++;
}

/**
 * Removes the value at position [pos] in the list
 */
void LinkedList_remove( LinkedList *list, int pos )
{
    assert( pos >= 0 && pos < list->size && list->size > 0);


    list->size--;
}

/**
 * Adds the value [val] to the front of the list
 */
void LinkedList_push_front( LinkedList *list, int val)
{
    Node *new = (Node*) malloc( sizeof(Node) );
    new->val = val;
    new->next = list->head;
    new->prev = NULL;

    list->size++;
}

/**
 * Adds the value [val] to the end of the list
 */
void LinkedList_push_end( LinkedList *list, int val)
{
    Node *new = (Node*) malloc( sizeof(Node) );
    new->val = val;
    new->next = NULL;
    new->prev = list->tail;


    list->size++;
}

/**
 * Removes and returns the value at the front of the list
 */
int LinkedList_pop_front( LinkedList *list )
{
    assert( list->size > 0 );

    int retVal;

    return retVal;
}

/**
 * Removes and returns the value at the end of the list
 */
int LinkedList_pop_end( LinkedList *list )
{
    assert( list->size > 0 );

    int retVal;

    list->size--;
    return retVal;
}

/**
 * Find the index of the first instance of value [val] in the list
 */
int LinkedList_find( LinkedList *list, int val )
{
    int idx = -1;

    for (Node *e = list->head; e; e=e->next) {
        idx++;

        if (e->val == val) {
            return idx;
        }
    }

    return idx;
}

/**
 * Print all items
 */
void LinkedList_print( LinkedList *list )
{
    printf("[");
    Node *entry = list->head;
    while (entry) {
        if (entry->next) {
            printf( "%d, ", entry->val );
        } else {
            printf( "%d", entry->val );
        }
        entry = entry->next;
    }
    printf("]\n");
}