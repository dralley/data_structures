/**
 * Implementation of a singly-linked list for 32-bit integers
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
};

/** LinkedList base struct */
struct llist_t {
    int size;
    Node *head;
};

/**
 * Return an empty LinkedList
 */
LinkedList *LinkedList_new()
{
    LinkedList *new = (LinkedList*) malloc( sizeof(LinkedList) );
    new->size = 0;
    new->head = NULL;

    return new;
}

/**
 * Delete and free the LinkedList
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

    Node **pp = &list->head;
    Node *entry = list->head;

    for (int i=0; i<pos; i++) {
        pp = &entry->next;
        entry = entry->next;
    }

    new->next = entry;
    *pp = new;

    list->size++;
}

/**
 * Removes the value at position [pos] in the list
 */
void LinkedList_remove( LinkedList *list, int pos )
{
    assert( pos >= 0 && pos < list->size && list->size > 0);

    Node **pp = &list->head;
    Node *entry = list->head;

    for (int i=0; i<pos; i++) {
        pp = &entry->next;
        entry = entry->next;
    }

    *pp = entry->next;
    free( entry );

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

    list->head = new;
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

    Node **pp = &list->head;
    Node *entry = list->head;

    while (entry) {
        pp = &entry->next;
        entry = entry->next;
    }

    new->next = entry;
    *pp = new;

    list->size++;
}

/**
 * Removes and returns the value at the front of the list
 */
int LinkedList_pop_front( LinkedList *list )
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
 * Removes and returns the value at the end of the list
 */
int LinkedList_pop_end( LinkedList *list )
{
    assert( list->size > 0 );

    int retVal;

    Node **pp = &list->head;
    Node *entry = list->head;

    while (entry) {
        if (entry->next == NULL) {
            retVal = entry->val;
            free( entry );
            *pp = NULL;
            break;
        }

        pp = &entry->next;
        entry = entry->next;
    }

    list->size--;
    return retVal;
}

/**
 * Find the index of the first instance of value [val] in the list, or -1 if not found
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
 * Print all items in the list
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