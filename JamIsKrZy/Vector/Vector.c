#include "./Vector.h"
#include <string.h>

bool push(Vector *vec, const void* data){
    if (vec == NULL) return false;

    if(vec->top == vec->cap) {
        size_t new_cap = vec->cap * 2;
        void *new_base = realloc(vec->base, vec->memsize * new_cap);
        if(new_base == NULL){
            free(vec);
            return false;
        }
        vec->base = new_base;
        vec->cap = new_cap;
    }
    void *mem_loc = ((char*)vec->base) + (vec->memsize * vec->top);
    memcpy(mem_loc, data, vec->memsize);
    vec->top++;
    return true;
}

bool pop(Vector *vec, void* returnData){
    if(vec == NULL && vec->base == NULL) return false;
    if(vec->top == 0) return false;

    void *mem_loc = ((char*)vec->base) + (vec->memsize * (vec->top-1));
    memcpy(returnData, mem_loc, vec->memsize);
    vec->top--;
    return true;
}