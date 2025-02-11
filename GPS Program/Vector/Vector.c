#include "./Vector.h"
#include <string.h>

Vector* new_box_vector(size_t memsize, size_t capacity){
    Vector *vec = malloc(sizeof(Vector));

    vec->base = malloc(memsize * capacity);
    if(vec->base == NULL) return NULL;
    vec->top = 0;
    vec->memsize = memsize;
    vec->cap = capacity;
    return vec;
}

Vector new_vector(size_t memsize, size_t capacity){
    Vector vec; 
    vec.base = malloc(memsize * capacity);
    vec.top = 0;
    vec.memsize = memsize;
    vec.cap = capacity;
    return vec;
}


bool push_vector(Vector *vec, const void* data){
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

bool pop_vector(Vector *vec, void* returnData){
    if(vec == NULL && vec->base == NULL) return false;
    if(vec->top == 0) return false;

    void *mem_loc = ((char*)vec->base) + (vec->memsize * (vec->top-1));
    memcpy(returnData, mem_loc, vec->memsize);
    vec->top--;
    return true;
}

void* get_vector(Vector *vec, size_t index){
    if(vec == NULL || vec->base == NULL || index >= vec->cap) return NULL;
    return ((char*)vec->base) + (vec->memsize * index);
}


void free_vector(Vector *vec){
    free(vec->base);
    free(vec);
}

#include <stdio.h>
void print_vector(Vector *vec, void (*format)(const void *value)){
    if(vec == NULL) return;

    printf("[ ");
    for (size_t i = 0; i < vec->top; i++)
    {
        format(((char*)vec->base) + (vec->memsize * i));
    }
    printf("]");
    
}