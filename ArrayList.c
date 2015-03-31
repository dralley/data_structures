#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "ArrayList.h"

/** ArrayList base struct */
struct arrlist_t {
    int size;
    int capacity;
    int *array;
};


/**
 * Return an empty ArrayList
 */
ArrayList *ArrayList_new()
{
    ArrayList *new = (ArrayList*) malloc( sizeof(ArrayList) );
    new->array = (int*) calloc( DEFAULT_SIZE, sizeof(int) );
    new->size = 0;
    new->capacity = DEFAULT_SIZE;

    return new;
}

/** Delete and free the ArrayList */
void ArrayList_delete( ArrayList *list )
{
    free( list->array );
    free( list );
}

/**
 * NOT EXPOSED
 * Increase the size of the allocated array for storing elements
 */
static void _increaseCapacity( ArrayList *list )
{
    list->array = (int*) realloc( list->array, list->capacity *= 2 );
}

/**
 * Return the size of the list
 */
int ArrayList_size( ArrayList *list )
{
    return list->size;
}

/**
 * Return the element at position [pos] in the list
 */
int ArrayList_get( ArrayList *list,  int pos )
{
    assert( pos >= 0 && pos < list->size );

    return list->array[ pos ];
}

/**
 * Insert the value [val] at position [pos] in the list
 */
void ArrayList_insert( ArrayList *list,  int val, int pos )
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
void ArrayList_remove( ArrayList *list, int pos )
{
    assert( pos >= 0 && pos < list->size );

    for (int i=pos; i < (list->size-1); i++) {
        list->array[ i ] = list->array[ i+1 ];
    }

    list->size--;
}

/**
 * Add the value [val] to the front of the list
 */
void ArrayList_push_front( ArrayList *list, int val)
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
void ArrayList_push_end( ArrayList *list, int val)
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
int ArrayList_pop_front( ArrayList *list )
{
    assert( list->size > 0 );

    int retVal = list->array[ 0 ];

    for (int i=1; i < (list->size-1); i++) {
        list->array[ i ] = list->array[ i-1 ];
    }
    list->size--;

    return retVal;
}

/**
 * Remove and return the last element in the list
 */
int ArrayList_pop_end( ArrayList *list )
{
    assert( list->size > 0 );

    int retVal = list->array[ list->size-1 ];

    for (int i=1; i < (list->size-1); i++) {
        list->array[ i ] = list->array[ i-1 ];
    }
    list->size--;

    return retVal;
}

/**
 * Find the index of the first instance of value [val] in the list, or -1 if not found
 */
int ArrayList_find( ArrayList *list, int val )
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
 * Print all items in the list
 */
void ArrayList_print( ArrayList *list )
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