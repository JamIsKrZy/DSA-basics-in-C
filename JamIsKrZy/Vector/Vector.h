#ifndef VECTOR_H_
#define VECTOR_H_

#include <stdlib.h>

typedef struct Vector{
    size_t length;
    size_t capacity;
    size_t top;
    void *base;
} Vector;

#define Init_Vector(memSize, capacity) {\
    .base = malloc(memSize * capacity), \
    .length = 0,                        \
    .top = 0,                           \
    .capacity = capacity                \
}

bool push();
bool pop();

bool set();
bool get();
bool search();


#endif