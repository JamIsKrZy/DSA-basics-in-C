#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdlib.h>
#include <stdbool.h>
/**
 * Only an implementation of singly linkedlist
 */

typedef struct SingleNode SingleNode;

typedef struct Linkedlist
{
    SingleNode *head;
    size_t length;
    size_t memSize;
}  Linkedlist;


Linkedlist* newLinkedlist(size_t memSize);

/**
 * Pushes on the head of the list
 */
bool push(Linkedlist *list, void* data);
bool pop(Linkedlist* list, void* returnValue);
/**
 * Works on single values
 */
bool delete(Linkedlist* list);

/**
 * Works on struct or array values
 */
bool delete_by(Linkedlist *list, void (*checker)(const void *validator, const void* value));

void linkedlist_print(Linkedlist *list, void (*printFormat)(void* val));
void free_linkedlist(Linkedlist *list);


#endif