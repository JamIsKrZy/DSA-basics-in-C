#include <string.h>
#include "List.h"

struct List{
    struct List *next;
    /**
     * Allocate another memory here
     */
};


List *newNode(size_t memsize){
    List *node = malloc(sizeof(List) + memsize);
    node->next = NULL;
    return node;
}

List *push_list(List **list, void *data, size_t memSize){
    List *new_node = newNode(memSize);
    if (!new_node) return NULL;

    memcpy(new_node + 1, data, memSize);
    new_node->next = *list;
    *list = new_node;
    return new_node;
}

void* search_by_list(List *list, void* data, bool (*compare)(void*, void*)){
    if(list == NULL) return NULL;
    
    while (list)
    {
        void *list_data = (void *)(list + 1);
        if (compare(data, list_data)) {
            return list_data;
        }
        list = list->next;
    }
    return NULL;
}


void free_list(List *list){
    List *next = NULL;

    while (list)
    {
        next = list->next;
        free(list);
        list = next;
    }

    free(list);
}



// /**
//  * Used for assertion purposes
//  * 
//  */
// #include <assert.h>

// struct nody{
//     int flame;
//     int cold;
// };

// bool lookintoCold(const void* val1,const void* val2){
//     return ((struct nody*)val1)->cold == ((struct nody*)val2)->cold; 
// }

// int main(int argc, char const *argv[])
// {   
//     struct nody test = {.cold = 22, .flame=25};
//     size_t mems = sizeof(struct nody);
//     List *list = NULL;

//     push_list(&list, &test, mems);
//     test.cold = 15;
//     push_list(&list, &test, mems);
//     test.cold = 12;
//     push_list(&list, &test, mems);
//     test.cold = 16;
//     push_list(&list, &test, mems);


//     test.cold = 15;
//     struct nody *catch = search_by_list(list, &test, lookintoCold);
//     assert(catch);
//     assert(catch->cold == 17? false: true);


//     free_list(list);
//     return 0;
// }
