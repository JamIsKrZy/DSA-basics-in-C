#ifndef VECTOR_H_
#define VECTOR_H_

#include <stdlib.h>
#include <stdbool.h>

typedef struct Vector{
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
    .top = 0,                           \
    .memsize = memSize,                 \
    .cap = capacity                \
}

Vector* new_box_vector(size_t memsize, size_t capacity);
Vector new_vector(size_t memsize, size_t capacity);


bool push_vector(Vector *vec, const void* data);
bool pop_vector(Vector *vec, void* returnData);

bool set();
void* get_vector(Vector *vec, size_t index);
bool search(Vector *vec, void* value, bool (*validate)(const void* value1, const void* value2));

void print_vector(Vector *vec, void (*format)(const void *value));

void free_vector(Vector *vec);

#endif