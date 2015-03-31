#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "LinkedList.h"
#include "ArrayList.h"

void ArrayList_tests()
{
    ArrayList *list = ArrayList_new();
    // []

    int ret;

    /** Test edge cases for push/pop front/end functions */
    ArrayList_push_end( list, 1 );
    ret = ArrayList_pop_end( list );

    assert(ret == 1);
    assert( ArrayList_size(list) == 0);

    ArrayList_push_front( list, 1 );
    ret = ArrayList_pop_front( list );
    // []

    assert(ret == 1);
    assert( ArrayList_size(list) == 0);

    /** Test non-edge case push end function */
    ArrayList_push_end( list, 1 );
    ArrayList_push_end( list, 2 );
    ArrayList_push_end( list, 3 );
    ArrayList_push_end( list, 4 );
    // [1, 2, 3, 4]

    /** Test values are in correct positions */
    ret = ArrayList_find( list, 1 );
    assert(ret == 0);
    ret = ArrayList_find( list, 2 );
    assert(ret == 1);
    ret = ArrayList_find( list, 4 );
    assert(ret == 3);

    assert(ArrayList_size(list) == 4);

    /** Test non-edge case push front function */
    ArrayList_push_front( list, 0 );
    // [0, 1, 2, 3, 4]

    assert(ArrayList_size(list) == 5);

    /** Test non-edge case pop front function */
    ret = ArrayList_pop_front( list );
    // [1, 2, 3, 4]

    assert(ret == 0);
    assert(ArrayList_size(list) == 4);

    /** Test positional inserting at the end of the list */
    ArrayList_insert( list, 5, 4);
    // [1, 2, 3, 4, 5]

    assert(ArrayList_size(list) == 5);

    /** Test all values are in correct spots */
    ret = ArrayList_get( list, 0 );
    assert(ret == 1);
    ret = ArrayList_get( list, 2 );
    assert(ret == 3);
    ret = ArrayList_get( list, 4 );
    assert(ret == 5);

    /** Test removing from the middle */
    ArrayList_remove( list, 2 );
    // [1, 2, 4, 5]

    assert(ArrayList_size(list) == 4 );

    /** Test positional inserting to the middle */
    ArrayList_insert( list, 3, 2);
    // [1, 2, 3, 4, 5]

    assert( ArrayList_size(list) == 5);

    /** Test non-edge case pop end function */
    ret = ArrayList_pop_end( list);
    // [1, 2, 3, 4]

    assert(ret == 5);
    assert( ArrayList_size(list) == 4);

    /** Test positional removing from the end */
    ArrayList_remove( list, 3 );
    // [1, 2, 3]

    /** Test positional removing from the front */
    ArrayList_remove( list, 0 );
    // [2, 3]

    assert( ArrayList_size(list) == 2);

    ret = ArrayList_get( list, 0 );
    assert(ret == 2);
    ret = ArrayList_get( list, 1 );
    assert(ret == 3);

    /** Test positional inserting at the front */
    ArrayList_insert( list, 1, 0 );
    // [1, 2, 3]

    ret = ArrayList_get( list, 1 );
    assert(ret == 2);

    // Valgrind verified no leaks
    ArrayList_delete( list );
}

void LinkedList_tests()
{
    LinkedList *list = LinkedList_new();
    // []

    int ret;

    /** Test edge cases for push/pop front/end functions */
    LinkedList_push_end( list, 1 );
    ret = LinkedList_pop_end( list );

    assert(ret == 1);
    assert( LinkedList_size(list) == 0);

    LinkedList_push_front( list, 1 );
    ret = LinkedList_pop_front( list );
    // []

    assert(ret == 1);
    assert( LinkedList_size(list) == 0);

    /** Test non-edge case push end function */
    LinkedList_push_end( list, 1 );
    LinkedList_push_end( list, 2 );
    LinkedList_push_end( list, 3 );
    LinkedList_push_end( list, 4 );
    // [1, 2, 3, 4]

    /** Test values are in correct positions */
    ret = LinkedList_find( list, 1 );
    assert(ret == 0);
    ret = LinkedList_find( list, 2 );
    assert(ret == 1);
    ret = LinkedList_find( list, 4 );
    assert(ret == 3);

    assert(LinkedList_size(list) == 4);

    /** Test non-edge case push front function */
    LinkedList_push_front( list, 0 );
    // [0, 1, 2, 3, 4]

    assert(LinkedList_size(list) == 5);

    /** Test non-edge case pop front function */
    ret = LinkedList_pop_front( list );
    // [1, 2, 3, 4]

    assert(ret == 0);
    assert(LinkedList_size(list) == 4);

    /** Test positional inserting at the end of the list */
    LinkedList_insert( list, 5, 4);
    // [1, 2, 3, 4, 5]

    assert(LinkedList_size(list) == 5);

    /** Test all values are in correct spots */
    ret = LinkedList_get( list, 0 );
    assert(ret == 1);
    ret = LinkedList_get( list, 2 );
    assert(ret == 3);
    ret = LinkedList_get( list, 4 );
    assert(ret == 5);

    /** Test removing from the middle */
    LinkedList_remove( list, 2 );
    // [1, 2, 4, 5]

    assert(LinkedList_size(list) == 4 );

    /** Test positional inserting to the middle */
    LinkedList_insert( list, 3, 2);
    // [1, 2, 3, 4, 5]

    assert( LinkedList_size(list) == 5);

    /** Test non-edge case pop end function */
    ret = LinkedList_pop_end( list);
    // [1, 2, 3, 4]

    assert(ret == 5);
    assert( LinkedList_size(list) == 4);

    /** Test positional removing from the end */
    LinkedList_remove( list, 3 );
    // [1, 2, 3]

    /** Test positional removing from the front */
    LinkedList_remove( list, 0 );
    // [2, 3]

    assert( LinkedList_size(list) == 2);

    ret = LinkedList_get( list, 0 );
    assert(ret == 2);
    ret = LinkedList_get( list, 1 );
    assert(ret == 3);

    /** Test positional inserting at the front */
    LinkedList_insert( list, 1, 0 );
    // [1, 2, 3]

    ret = LinkedList_get( list, 1 );
    assert(ret == 2);

    // Valgrind verified no leaks
    LinkedList_delete( list );
}

int main() {
    LinkedList_tests();
    ArrayList_tests();
}
