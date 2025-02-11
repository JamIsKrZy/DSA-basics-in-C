#include <stdio.h>
#include "./DS/Vector.h"
#include "./DS/VectorIterator.h"

// Add some
void set_up_vector(Vector *vec){
    int n, to_push;

    //  Think of ranom inserting values in the vector
    for (int i = 0; i < 23; i++)
    {     
        n = (i*7) % 4;    

        if(n == 0){
            to_push = i*2;
            push_vector(vec, &to_push);
        } else if(n == 1){
            to_push = i*5+31;
            push_vector(vec, &to_push);
        } else if(n == 2){
            to_push = i*9+44;
            push_vector(vec, &to_push);
        } else {
            to_push = i*7+23;
            push_vector(vec, &to_push);
        }
    }
    
}

void print_vec_format(const void *value){
    printf("%d ", *((int*)value));
}

int main(int argc, char const *argv[])
{   
    //Sets the vector to have 30 capacity size of integer
    Vector vec = Init_Vector(sizeof(int), 30);
    // insert 24 values in thee vector (vector length is 24)
    set_up_vector(&vec); 

    printf("Inside the Vector: ");
    print_vector(&vec, print_vec_format);

    printf("\n----------------------------------------------------------------------\n");


    //Vectors borrows a referenc to the vector data structure
    // for safe code, do not mutate vec before iterator is done
    VecIterator iter_vec = get_iter_vector(&vec);

    /**
     * In python this is:
     * for i in list
     */
    for (void *i; i = VecIterator_next(&iter_vec);)
    {
        // print out what came out from the next iterator
        printf("(Called Next) value=%d\n", *((int*)i));
    }



    printf("\n----------------------------------------------------------------------\n");
    // In enumrate method
    VecIterator iter_vec_2 = get_iter_vector(&vec);
    
    struct enumurate e = VecIterator_enumerate(&iter_vec_2);
    for (; e.mem_loc_ptr != NULL; e = VecIterator_enumerate(&iter_vec_2)) {
        // Process each element
        printf("{ .index=%ld , .value=%d }\n", e.index, *((int*)e.mem_loc_ptr));
    }
    






    return 0;
}
