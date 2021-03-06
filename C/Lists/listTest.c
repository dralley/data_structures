#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

/**
 * Test implementations of "List.h" by linking them against this program
 */
int main()
{
    List *list = List_new();
    // []

    int ret;

    /** Test edge cases for push/pop front/end functions */
    List_push_end( list, 1 );
    ret = List_pop_end( list );

    assert(ret == 1);
    assert( List_size(list) == 0);

    List_push_front( list, 1 );
    ret = List_pop_front( list );
    // []

    assert(ret == 1);
    assert( List_size(list) == 0);

    /** Test non-edge case push end function */
    List_push_end( list, 1 );
    List_push_end( list, 2 );
    List_push_end( list, 3 );
    List_push_end( list, 4 );
    // [1, 2, 3, 4]

    /** Test values are in correct positions */
    ret = List_find( list, 1 );
    assert(ret == 0);
    ret = List_find( list, 2 );
    assert(ret == 1);
    ret = List_find( list, 4 );
    assert(ret == 3);

    assert(List_size(list) == 4);

    /** Test non-edge case push front function */
    List_push_front( list, 0 );
    // [0, 1, 2, 3, 4]

    assert(List_size(list) == 5);

    /** Test non-edge case pop front function */
    ret = List_pop_front( list );
    // [1, 2, 3, 4]

    assert(ret == 0);
    assert(List_size(list) == 4);

    /** Test positional inserting at the end of the list */
    List_insert( list, 5, 4);
    // [1, 2, 3, 4, 5]

    assert(List_size(list) == 5);

    /** Test all values are in correct spots */
    ret = List_get( list, 0 );
    assert(ret == 1);
    ret = List_get( list, 2 );
    assert(ret == 3);
    ret = List_get( list, 4 );
    assert(ret == 5);

    /** Test removing from the middle */
    ret = List_remove( list, 2 );
    assert(ret == 3);
    // [1, 2, 4, 5]

    assert(List_size(list) == 4);

    /** Test positional inserting to the middle */
    List_insert( list, 3, 2);
    // [1, 2, 3, 4, 5]

    assert( List_size(list) == 5);

    /** Test non-edge case pop end function */
    ret = List_pop_end(list);
    // [1, 2, 3, 4]

    assert(ret == 5);
    assert( List_size(list) == 4);

    /** Test positional removing from the end */
    ret = List_remove( list, 3 );
    assert(ret == 4);
    // [1, 2, 3]

    /** Test positional removing from the front */
    ret = List_remove( list, 0 );
    assert(ret == 1);
    // [2, 3]

    assert( List_size(list) == 2);

    ret = List_get( list, 0 );
    assert(ret == 2);
    ret = List_get( list, 1 );
    assert(ret == 3);

    /** Test positional inserting at the front */
    List_insert( list, 1, 0 );
    // [1, 2, 3]

    ret = List_get( list, 1 );
    assert(ret == 2);

    List *extend = List_new();
    List_push_end(extend, 4);
    List_push_end(extend, 5);
    List_push_end(extend, 6);
    // [4, 5, 6]


    List_extend(list, extend);
    // [1, 2, 3, 4, 5, 6]

    for (int i=0; i<6; i++) {
        assert( List_get(list, i) == i+1 );
    }

    /** Test adding a lot of elements, mostly for ArrayList */
    for (int i=0; i<244; i++) {
        List_push_end( list, -1 );
    }

    assert( List_size(list) == 250 );

    List *extend2 = List_new();
    List_push_end(extend2, 4);
    List_push_end(extend2, 5);
    List_push_end(extend2, 6);

    assert(List_equal(extend, extend2));

    List_destroy(list);
}
