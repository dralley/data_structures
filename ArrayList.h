#ifndef _ARRAY_LIST_H_
#define _ARRAY_LIST_H_

#define DEFAULT_SIZE 100

/** Struct impelementations in source */
typedef struct arrlist_t ArrayList;

/** ArrayList interface */
ArrayList *ArrayList_new();
void ArrayList_delete( ArrayList *list );
int ArrayList_size( ArrayList *list );
int ArrayList_get( ArrayList *list,  int pos );
void ArrayList_insert( ArrayList *list,  int val, int pos );
void ArrayList_remove( ArrayList *list, int pos );
void ArrayList_push_front( ArrayList *list, int val);
void ArrayList_push_end( ArrayList *list, int val);
int ArrayList_pop_front( ArrayList *list );
int ArrayList_pop_end( ArrayList *list );
int ArrayList_find( ArrayList *list, int val );
void ArrayList_print( ArrayList *list );

#endif