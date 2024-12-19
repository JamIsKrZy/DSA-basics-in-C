#ifndef HASHMAP_H_
#define HASHMAP_H_
#include <stdlib.h>
#include <stdbool.h>



typedef struct ChainedHashMap ChainedHashMap;

ChainedHashMap *new_chained_hashmap(size_t memsize, size_t arrSize);

bool insert_hashmap(ChainedHashMap *map, char *key, void *value);
void* get_value_hashmap(ChainedHashMap *map, char *key);

void free_hashmap(ChainedHashMap *map);

#endif