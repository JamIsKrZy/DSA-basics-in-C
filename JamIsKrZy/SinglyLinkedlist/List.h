#ifndef LINKEDLIST_H_REV
#define LINKEDLIST_H_REV
#include <stdlib.h>
#include <stdbool.h>

/**
 * This library is used only when used in combining complex structure
 */
typedef struct List List;

List *push_list(List **list, void *data, size_t memSize);

void* search_by_list(List *list, void* data, bool (*compare)( void*, void*));

void free_list(List *list);



#endif