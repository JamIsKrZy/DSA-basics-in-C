#include "Hashmap.h"
#include "../SinglyLinkedlist/List.h"
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

struct Content{
    char *key;
    /**
     * Allocate Data (memsize)
     */
};

struct ChainedHashMap {
    List **base;
    size_t cap;
    size_t memsize;
};


static size_t fnv1a(const char *key) {
    // Define FNV-1a constants based on the size of size_t
    size_t fnv_offset_basis;
    size_t fnv_prime;

    if (sizeof(size_t) == 4) { // 32-bit size_t
        fnv_offset_basis = 2166136261U;
        fnv_prime = 16777619U;
    } else { // 64-bit size_t
        fnv_offset_basis = 14695981039346656037UL;
        fnv_prime = 1099511628211UL;
    }

    size_t hash = fnv_offset_basis;

    // Perform the FNV-1a hash algorithm
    for (const char *p = key; *p != '\0'; ++p) {
        hash ^= (unsigned char)(*p); // XOR with the byte
        hash *= fnv_prime;           // Multiply by the prime
    }

    return hash;
}

ChainedHashMap *new_chained_hashmap(size_t memsize, size_t arrSize){
    ChainedHashMap *map = malloc(sizeof(ChainedHashMap));

    map->base = calloc(arrSize,sizeof(List*));
    map->cap = arrSize;
    map->memsize = memsize;
    return map;
}

static bool compare_key_pairs(void *key, void *fromList){
    return !strcmp((char*)key,((struct Content*)fromList)->key);
}

bool insert_hashmap(ChainedHashMap *map, char *key, void *value){
    if(map == NULL) return false;

    List **bucket = map->base + (fnv1a(key) % map->cap);
    
    if(search_by_list(*bucket, key, compare_key_pairs)){
        return false;
    }

    size_t total_alloc = sizeof(struct Content) + map->memsize;

    struct Content *content = malloc(total_alloc);
    content->key = key;
    memcpy(content+1, value, map->memsize);

    push_list(bucket, content, total_alloc);

    free(content);
    return true;
    //hash they key
    //get the bucket
    //Set the choosen bucket to insert a node (sizeof(struct content) + memSize)
    //check if there are same key values
}

void* get_value_hashmap(ChainedHashMap *map, char *key){
    if(map == NULL) return NULL;

    List **bucket = map->base + (fnv1a(key) % map->cap);
    struct Content *get = search_by_list(*bucket, key, compare_key_pairs);
    if(get == NULL) return NULL;
    return get+1;
}

void free_hashmap(ChainedHashMap *map){

    for (size_t i = 0; i < map->cap; i++)
    {
        free_list(map->base[i]);
    }
    
    free(map->base);
    free(map);
}




