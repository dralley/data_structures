/**
 * @author Daniel Alley (dralley)
 *
 * Implementation of a doubly-linked list for 32-bit integers
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/** Prototypes for the functions common to all List implementations */
#include "list.h"

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

/**
 * Create an empty List
 */
List *List_new()
{
    List *new = (List*) malloc( sizeof(List) );
    new->size = 0;
    new->head = NULL;
    new->tail = NULL;

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

    Node *current = list->head;
    for (int i = 0; i < pos; i++) {
        current = current->next;
    }

    // Initialize new node
    Node *new = (Node*) malloc( sizeof(Node) );
    new->val = val;
    new->next = NULL;
    new->prev = NULL;

    if (pos == list->size) {
        new->prev = list->tail;
        list->tail->next = new;
        list->tail = new;
    } else if (pos == 0) {
        new->next = list->head;
        list->head->prev = new;
        list->head = new;
    } else {
        new->next = current;
        new->prev = current->prev;
        current->prev->next = new;
        current->prev = new;
    }

    list->size++;
}

/**
 * Remove the value at position [pos] from the list
 */
int List_remove( List *list, int pos )
{
    assert( pos >= 0 && pos < list->size && list->size > 0);

    Node *current = list->head;
    for (int i = 0; i < pos; i++) {
        current = current->next;
    }
    int ret = current->val;

    if (pos == 0) {
        current->next->prev = NULL;
        list->head = current->next;
    } else if (pos == list->size -1) {
        current->prev->next = NULL;
        list->tail = current->prev;
    } else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
    free( current );

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
    new->prev = NULL;

    list->head = new;
    list->size++;

    if (list->size == 1) {
        list->tail = new;
    }
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
    new->prev = list->tail;

    list->size++;

    if (list->size == 1) {
        list->head = new;
        list->tail = new;
    } else {
        list->tail->next = new;
        list->tail = new;
    }
}

/**
 * Remove and return the first element in the list
 */
int List_pop_front( List *list )
{
    assert( list->size > 0 );

    Node *old_head = list->head;
    int retVal = old_head->val;

    list->head = old_head->next;

    if (list->head) {
        list->head->prev = NULL;
    } else {
        list->tail = list->head;
    }

    list->size--;
    free( old_head );
    return retVal;
}

/**
 * Remove and return the last element in the list
 */
int List_pop_end( List *list )
{
    assert( list->size > 0 );

    Node *old_tail = list->tail;
    int retVal = old_tail->val;

    list->tail = old_tail->prev;

    if (list->tail) {
        list->tail->next = NULL;
    } else {
        list->head = list->tail;
    }

    list->size--;
    free( old_tail );
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
void List_extend(List *list, List *extend)
{
    for (Node *e = extend->head; e; e = e->next) {
        Node *new = (Node *)malloc(sizeof(Node));
        new->val = e->val;
        new->next = NULL;

        list->tail->next = new;
        list->tail = new;
        list->size++;
    }
}

/**
 * Determine whether a list is equal to a second list
 */
bool List_equal(List *list1, List *list2)
{
    if (list1->size != list2->size) {
        return false;
    }

    Node *item1 = list1->head;
    Node *item2 = list2->head;

    for (int i = 0; i < list1->size; i++) {
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
            printf("%d, ", entry->val);
        }
        else {
            printf("%d", entry->val);
        }
        entry = entry->next;
    }
    printf("]\n");
    // printf("-------------------------\n");

    // if (list->head != NULL) {
    //     printf("head: %d         ", list->head->val);
    // } else {
    //     printf("head: NULL       ");
    // }

    // if (list->tail != NULL) {
    //     printf("tail: %d\n", list->tail->val);
    // } else {
    //     printf("tail: NULL\n");
    // }
    // printf("-------------------------\n");

    // entry = list->head;
    // while (entry) {
    //     printf("%d: ", entry->val);
    //     if (entry->prev) {
    //         printf("prev: %d    ; ", entry->prev->val);
    //     } else {
    //         printf("prev: NULL ; ");
    //     }
    //     if (entry->next) {
    //         printf("next: %d\n", entry->next->val);
    //     } else {
    //         printf("next: NULL\n");
    //     }
    //     entry = entry->next;
    // }
    // printf("==========================\n");
}
