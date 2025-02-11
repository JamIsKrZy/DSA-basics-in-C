#include "./VectorIterator.h"
#include "./Vector.h"

struct enumurate VecIterator_enumerate(VecIterator *iter_ref){
    struct enumurate enumerate = {.index = 0, .mem_loc_ptr = NULL};

    if(iter_ref->iter_index >= iter_ref->vec_ref->top) return enumerate;

    enumerate.mem_loc_ptr = 
        ((char*)(iter_ref->vec_ref->base)) + ((iter_ref->vec_ref->memsize) * (iter_ref->iter_index));

    enumerate.index = iter_ref->iter_index; 


    iter_ref->iter_index += 1;
    return enumerate;
}

// til it reeaches the end of the vector (not capacity - but length)
void* VecIterator_next(VecIterator *iter_ref){
    if(iter_ref->iter_index >= iter_ref->vec_ref->top) return NULL;

    void* ref = ((char*)(iter_ref->vec_ref->base)) + ((iter_ref->vec_ref->memsize) * (iter_ref->iter_index));

    iter_ref->iter_index += 1;
    return ref;
}
