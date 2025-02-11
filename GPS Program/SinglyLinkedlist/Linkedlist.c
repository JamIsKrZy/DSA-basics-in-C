#include "./Linkedlist.h"

#include <stdio.h>
#include <string.h>

struct SingleNode{
    SingleNode *next;
    /**
     * Allocate another for memSize
     */
};

static SingleNode* createSinglyNode(size_t memSize, void* data){
    SingleNode* node = malloc(sizeof(SingleNode) + memSize);
    if(node == NULL) return NULL;
    node->next = NULL;
    memcpy(node+1, data, memSize);
    return node;
}

Linkedlist* newLinkedlist(size_t memSize){
    Linkedlist *list = malloc(sizeof(Linkedlist));
    if(list == NULL) return NULL;
    list->head = NULL;
    list->length = 0;
    list->memSize = memSize;
    return list;
}

bool push(Linkedlist *list, void* data){
    if(list == NULL) return NULL;
    if(list->head == NULL) {
        SingleNode* node = createSinglyNode(list->memSize, data);
        if (node == NULL) return false;

        list->head = node;
        list->length++;
        return true;
    }

    SingleNode* node = createSinglyNode(list->memSize, data);
    if(node == NULL) return false;
    node->next = list->head;
    list->head = node;
    list->length++;
    return true;
}

bool pop(Linkedlist* list, void* returnValue){
    if(list == NULL || list->head == NULL) return false;

    SingleNode* node = list->head;
    memcpy(returnValue, node+1, list->memSize);
    list->head = node->next;
    list->length--;
    free(node);
    return true;
}

void linkedlist_print(Linkedlist *list, void (*printFormat)(void* val)){
    if(list == NULL) return;

    SingleNode *node = list->head;
    printf("[ ");
    while (node)
    {
        printFormat(node+1);
        node = node->next;
    }
    printf("]\n");
}

void free_linkedlist(Linkedlist *list){
    SingleNode *curr = list->head, *next = NULL;

    while (curr)
    {
        next = curr->next;
        free(curr);
        curr = next;
    }

    free(list);
}

/**
 * -------------------------------------------------------------------------
 * -------------------------------------------------------------------------
 * -------------------------------------------------------------------------
 * -------------------------------------------------------------------------
 * -------------------------------------------------------------------------
 * 
 * SAMPLE OF USING LINKEDLIST
 * 
 */
struct Watermelon{
    char *name;
    int width;
    int radius;
};

void watermelonPrintFormat(void* value){
    struct Watermelon* melon = value;
    printf("{ .name = \"%s\", .width = %d, .radius = %d }", melon->name , melon->width, melon->radius);
}

int main()
{
    Linkedlist *list = newLinkedlist(sizeof(struct Watermelon));

    struct Watermelon test = {.name="Wait for minute", .radius = 5, .width=10};
    push(list, &test);
    struct Watermelon test1 = {.name="Lets fo win a game", .radius = 69, .width=1};
    push(list, &test1);
    struct Watermelon test2 = {.name="Let's shake it", .radius = 44, .width=100};
    push(list, &test2);


    linkedlist_print(list, watermelonPrintFormat);
    free_linkedlist(list);
    return 0;
}

