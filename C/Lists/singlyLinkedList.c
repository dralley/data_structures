/**
 * @author Daniel Alley (dralley)
 *
 * Implementation of a singly-linked list for 32-bit integers
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/** Prototypes for the functions common to all List implementations */
#include "list.h"

/**
 * Singly-linked implementation of the linked list node
 */
typedef struct node_t {
    int val;
    struct node_t *next;
} Node;

/** Linked list base struct */
struct list_t {
    int size;
    Node *head;
};

/**
 * Create an empty List
 */
List *List_new()
{
    List *new = (List*) malloc( sizeof(List) );
    new->size = 0;
    new->head = NULL;

    return new;
}

/**
 * Delete and free the List
 */
void List_destroy( List *list )
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
 * Return the size of the list
 */
int List_size( List *list )
{
    return list->size;
}

/**
 * Return the element at position [pos] in the list
 */
int List_get( List *list, int pos )
{
    assert( pos >= 0 && pos < list->size );

    Node *entry = list->head;
    for (int i=0; i<pos; i++) {
        entry = entry->next;
    }

    return entry->val;
}

/**
 * Insert the value [val] at position [pos] in the list
 */
void List_insert( List *list, int val, int pos )
{
    assert( pos >= 0 && pos <= list->size );

    // Initialize new node
    Node *new = (Node*) malloc( sizeof(Node) );
    new->val = val;

    Node **pp = &list->head;
    Node *entry = list->head;

    // Traverse to the point where entry is the node to be
    // replaced by new, and pp is the 'next' pointer to entry
    for (int i=0; i<pos; i++) {
        pp = &entry->next;
        entry = entry->next;
    }

    new->next = entry;
    *pp = new;

    list->size++;
}

/**
 * Remove the value at position [pos] from the list
 */
int List_remove( List *list, int pos )
{
    assert( pos >= 0 && pos < list->size && list->size > 0);

    Node **pp = &list->head;
    Node *entry = list->head;

    // Traverse to the point where entry is the node to be
    // removed, and pp is the 'next' pointer to entry
    for (int i=0; i<pos; i++) {
        pp = &entry->next;
        entry = entry->next;
    }

    int ret = entry->val;

    // Set the 'next' pointer pointing to the node to be removed
    // to the new node
    *pp = entry->next;
    free( entry );

    list->size--;
    return ret;
}

/**
 * Add the value [val] to the front of the list
 */
void List_push_front( List *list, int val)
{
    // Initialize new node
    Node *new = (Node*) malloc( sizeof(Node) );
    new->val = val;
    new->next = list->head;

    list->head = new;
    list->size++;
}

/**
 * Insert value [val] at the end of the list
 */
void List_push_end( List *list, int val)
{
    // Inititalize new node
    Node *new = (Node*) malloc( sizeof(Node) );
    new->val = val;
    new->next = NULL;

    Node **pp = &list->head;
    Node *entry = list->head;

    // Traverse to the end of the list, where entry is null,
    // and pp is the last 'next' pointer
    while (entry) {
        pp = &entry->next;
        entry = entry->next;
    }

    // Point the last 'next' pointer to the new node
    *pp = new;

    list->size++;
}

/**
 * Remove and return the first element in the list
 */
int List_pop_front( List *list )
{
    assert( list->size > 0 );

    Node *head = list->head;
    int retVal = head->val;

    list->head = head->next;
    list->size--;

    free( head );
    return retVal;
}

/**
 * Remove and return the last element in the list
 */
int List_pop_end( List *list )
{
    assert( list->size > 0 );

    int retVal;

    Node **pp = &list->head;
    Node *entry = list->head;

    // Traverse to the end of the list, where entry is null,
    // and pp is the last 'next' pointer
    while (entry && entry->next) {
        pp = &entry->next;
        entry = entry->next;
    }

    retVal = entry->val;
    free( entry );
    *pp = NULL;

    list->size--;
    return retVal;
}

/**
 * Find the index of the first instance of value [val] in the list, or -1 if not found
 */
int List_find( List *list, int val )
{
    int idx = 0;

    for (Node *e = list->head; e; e=e->next) {
        if (e->val == val) {
            return idx;
        }
        idx++;
    }

    return -1;
}

/**
 * Extend the list with the contents of a second list
 */
void List_extend( List *list, List *extend )
{
    Node **pp = &list->head;
    Node *entry = list->head;
    // Traverse to the end of the list, where entry is null,
    // and pp is the last 'next' pointer
    while (entry) {
        pp = &entry->next;
        entry = entry->next;
    }

    for (Node *e = extend->head; e; e = e->next) {
        Node *new = (Node *)malloc(sizeof(Node));
        new->val = e->val;
        new->next = NULL;

        *pp = new;
        pp = &new->next;
        list->size++;
    }
}

/**
 * Determine whether a list is equal to a second list
 */
bool List_equal(List *list1, List *list2)
{
    if (list1->size != list2->size)
    {
        return false;
    }

    Node *item1 = list1->head;
    Node *item2 = list2->head;

    for (int i=0; i<list1->size; i++) {
        if (item1->val != item2->val) {
            return false;
        }
        item1 = item1->next;
        item2 = item2->next;
    }

    return true;
}

/**
 * Print all items in the list
 */
void List_print( List *list )
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
