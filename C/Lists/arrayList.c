#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

// Default capacity of the ArrayList
#define DEFAULT_CAPACITY 100

/** List base struct */
struct list_t {
    int size;
    int capacity;
    int *array;
};


/**
 * Create an empty ArrayList
 */
List *List_new()
{
    List *new = (List*) malloc( sizeof(List) );
    new->array = (int*) calloc( DEFAULT_CAPACITY, sizeof(int) );
    new->size = 0;
    new->capacity = DEFAULT_CAPACITY;

    return new;
}

/**
 * Delete and free the List
 */
void List_destroy( List *list )
{
    free( list->array );
    free( list );
}

/**
 * NOT EXPOSED
 * Increase the size of the allocated array for storing elements
 */
static void _increaseCapacity( List *list )
{
    list->capacity *= 2;
    list->array = (int*) realloc( list->array, list->capacity * sizeof(int) );
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
int List_get( List *list,  int pos )
{
    assert( pos >= 0 && pos < list->size );

    return list->array[ pos ];
}

/**
 * Insert the value [val] at position [pos] in the list
 */
void List_insert( List *list,  int val, int pos )
{
    assert( pos >= 0 && pos <= list->size );

    if (list->size + 1 >= list->capacity) {
        _increaseCapacity( list );
    }

    for (int i=list->size; i>pos; i--) {
        list->array[ i ] = list->array[ i-1 ];
    }

    list->array[ pos ] = val;
    list->size++;
}

/**
 * Remove the value at position [pos] from the list
 */
int List_remove( List *list, int pos )
{
    assert( pos >= 0 && pos < list->size );

    int ret = list->array[pos];

    for (int i=pos; i < (list->size-1); i++) {
        list->array[ i ] = list->array[ i+1 ];
    }

    list->size--;
    return ret;
}

/**
 * Add the value [val] to the front of the list
 */
void List_push_front( List *list, int val)
{
    if (list->size + 1 >= list->capacity) {
        _increaseCapacity( list );
    }

    for (int i=list->size; i>0; i--) {
        list->array[ i ] = list->array[ i-1 ];
    }

    list->array[ 0 ] = val;
    list->size++;
}

/**
 * Insert value [val] at the end of the list
 */
void List_push_end( List *list, int val)
{
    if (list->size + 1 >= list->capacity) {
        _increaseCapacity( list );
    }

    list->array[ list->size ] = val;
    list->size++;
}

/**
 * Remove and return the first element in the list
 */
int List_pop_front( List *list )
{
    assert( list->size > 0 );

    int retVal = list->array[ 0 ];

    for (int i=0; i < (list->size-1); i++) {
        list->array[ i ] = list->array[ i+1 ];
    }
    list->size--;

    return retVal;
}

/**
 * Remove and return the last element in the list
 */
int List_pop_end( List *list )
{
    assert( list->size > 0 );

    int retVal = list->array[ list->size-1 ];
    list->size--;

    return retVal;
}

/**
 * Find the index of the first instance of value [val] in the list, or -1 if not found
 */
int List_find( List *list, int val )
{
    assert( list->size > 0 );

    int idx = -1;

    for (int i=0; i<list->size; i++) {
        if (list->array[ i ] == val) {
            idx = i;
            break;
        }
    }

    return idx;
}

/**
 * Extend the list with the contents of a second list
 */
void List_extend( List *list, List *extend )
{
    while (list->capacity < list->size + extend->size) {
        _increaseCapacity(list);
    }

    for (int i=0; i<extend->size; i++) {
        list->array[list->size++] = extend->array[i];
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

    for (int i=0; i<list1->size; i++) {
        if (list1->array[i] != list2->array[i]) {
            return false;
        }
    }

    return true;
}

/**
 * Print all items in the list
 */
void List_print( List *list )
{
    printf("[");

    for (int i=0; i < list->size; i++) {
        if (i != list->size - 1) {
            printf("%d, ", list->array[ i ]);
        } else {
            printf("%d", list->array[ i ]);
        }
    }

    printf("]\n");
}
