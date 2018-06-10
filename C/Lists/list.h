/**
 * @author Daniel Alley (dralley)
 *
 * Function prototypes for a generic list of integers
 */
#include <stdbool.h>
#ifndef _LIST_H_
#define _LIST_H_

/** Struct implementations in source files */
typedef struct list_t List;

/******** List interface ********/

/**
 * Create a new empty List
 *
 * @return An empty List of size 0
 */
List *List_new( );

/**
 * Destroy and free the List
 *
 * @param list List to destroy
 */
void List_destroy( List *list );

/**
 * Return the number of integers in the List
 *
 * @param  list List to operate on
 * @return      number of integers in the list
 */
int List_size( List *list );

/**
 * Return the integer at a position in the List
 *
 * @param  list List to operate on
 * @param  pos  0-indexed position in the list
 * @return      integer at specified position
 */
int List_get( List *list,  int pos );

/**
 * Insert an integer into a position in the List
 *
 * @param list List to operate on
 * @param val  integer value to insert
 * @param pos  0-indexed position in the list
 */
void List_insert( List *list,  int val, int pos );

/**
 * Remove an integer from a position in the List
 *
 * @param list List to operate on
 * @param pos  0-indexed position of the integer to remove
 */
int List_remove( List *list, int pos );

/**
 * Insert an integer to the very beginning of the List (index 0)
 *
 * @param list List to operate on
 * @param val  integer value to insert
 */
void List_push_front( List *list, int val);

/**
 * Insert an integer to the very end of the List
 *
 * @param list List to operate on
 * @param val  integer value to insert
 */
void List_push_end( List *list, int val);

/**
 * Remove and return the integer at the very beginning of the list
 *
 * @param  list List to operate on
 * @return      integer value to insert
 */
int List_pop_front( List *list );

/**
 * Remove and return the integer at the very end of the list
 *
 * @param  list List to operate on
 * @return      integer value to insert
 */
int List_pop_end( List *list );

/**
 * Return the index of the first occurrence of integer, or -1 if not found
 *
 * @param  list List to operate on
 * @param  val  integer value to find
 * @return      index of the first occurrence of val, or else -1 if not found
 */
int List_find( List *list, int val );

/**
 * Append the contents of a list onto another list
 *
 * @param  list    List to operate on
 * @param  extend  List to append onto the first
 */
void List_extend( List *list, List *extend );

/**
 * Determine whether the list is equal to a second list
 *
 * @param  list1  First list
 * @param  list2  Second list
 */
bool List_equal( List *list1, List *list2 );

/**
 * Print out the list to stdout (debugging function)
 *
 * @param list List to operate on
 */
void List_print( List *list );

#endif
