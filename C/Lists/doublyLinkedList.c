/**
 * @author Daniel Alley (dralley)
 *
 * Implementation of a doubly-linked list for 32-bit integers
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/** Prototypes for the functions common to all List implementations */
#include "include/list.h"

/**
 * Doubly-linked implementation of the linked list node
 */
typedef struct node_t {
    int val;
    struct node_t *next;
    struct node_t *prev;
} Node;

/** Linked list base struct */
struct list_t {
    int size;
    Node *head;
    Node *tail;
};

List *List_new()
{
    List *new = (List*) malloc( sizeof(List) );
    new->size = 0;
    new->head = NULL;
    new->tail = NULL;

    return new;
}

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

int List_size( List *list )
{
    return list->size;
}

/**
 * Get integer at position [pos] in the list
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
 * Insert integer [val] at position [pos] in the list
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

void List_remove( List *list, int pos )
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

    // Set the 'next' pointer pointing to the node to be removed
    // to the new node
    *pp = entry->next;
    free( entry );

    list->size--;
}

void List_push_front( List *list, int val)
{
    // Initialize new node
    Node *new = (Node*) malloc( sizeof(Node) );
    new->val = val;
    new->next = list->head;

    list->head = new;

    if (list->size == 0) {
        list->tail = new;
    }

    list->size++;
}

void List_push_end( List *list, int val)
{
    // Inititalize new node
    Node *new = (Node*) malloc( sizeof(Node) );
    new->val = val;
    new->next = NULL;

    list->tail = new;

    if (list->size == 0) {
        list->head = new;
    }

    list->size++;
}

int List_pop_front( List *list )
{
    assert( list->size > 0 );

    Node *head = list->head;
    int retVal = head->val;

    list->head = head->next;

    if (list->size == 1) {
        list->tail = NULL;
    }

    list->size--;

    free( head );
    return retVal;
}

int List_pop_end( List *list )
{
    assert( list->size > 0 );

    int retVal = list->tail->val;

    Node *old_tail = list->tail;
    list->tail = list->tail->prev;

    free( old_tail );

    list->size--;
    return retVal;
}

int List_find( List *list, int val )
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
