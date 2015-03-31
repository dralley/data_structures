#ifndef _LIST_H_
#define _LIST_H_

/** Struct impelementations in source */
typedef struct list_t List;

/** List interface */
List *List_new();
void List_delete( List *list );
int List_size( List *list );
int List_get( List *list,  int pos );
void List_insert( List *list,  int val, int pos );
void List_remove( List *list, int pos );
void List_push_front( List *list, int val);
void List_push_end( List *list, int val);
int List_pop_front( List *list );
int List_pop_end( List *list );
int List_find( List *list, int val );
void List_print( List *list );

#endif