#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

/** Struct impelementations in source */
typedef struct node_t Node;
typedef struct llist_t LinkedList;

/** LinkedList interface */
LinkedList *LinkedList_new();
void LinkedList_delete( LinkedList *list );
int LinkedList_size( LinkedList *list );
int LinkedList_get( LinkedList *list,  int pos );
void LinkedList_insert( LinkedList *list,  int val, int pos );
void LinkedList_remove( LinkedList *list, int pos );
void LinkedList_push_front( LinkedList *list, int val);
void LinkedList_push_end( LinkedList *list, int val);
int LinkedList_pop_front( LinkedList *list );
int LinkedList_pop_end( LinkedList *list );
int LinkedList_find( LinkedList *list, int val );
void LinkedList_print( LinkedList *list );

#endif