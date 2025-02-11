#ifndef Vector_Iterator_H
#define Vector_Iterator_H

#include <stddef.h>
typedef struct Vector Vector;

typedef struct VecIterator VecIterator;


struct VecIterator{
    Vector *vec_ref;
    int iter_index;
};

struct enumurate{
    size_t index;
    void* mem_loc_ptr;
};

struct enumurate VecIterator_enumerate(VecIterator *iter_ref);

void* VecIterator_next(VecIterator *iter_ref);




#endif