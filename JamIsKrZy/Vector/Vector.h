#ifndef VECTOR_H_
#define VECTOR_H_

#include <stdlib.h>
#include <stdbool.h>

typedef struct Vector{
    size_t length;
    size_t cap;
    size_t top;
    size_t memsize;
    void *base;
} Vector;

/**
 * Used only in stack memory
 */
#define Init_Vector(memSize, capacity) {\
    .base = malloc(memSize * capacity), \
    .length = 0,                        \
    .top = 0,                           \
    .memsize = memSize,                 \
    .cap = capacity                \
}

bool push(Vector *vec, const void* data);
bool pop(Vector *vec, void* returnData);

bool set();
bool get();
bool search();


#endif