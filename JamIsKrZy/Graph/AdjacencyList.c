#include "./AdjacencyList.h"
#include "../Vector/Vector.h"

struct Edges{
    size_t weight;
    size_t vertix;
};


// Vector<Vector<node>>
//problem, how to identify vertix
struct AdjListGraph{
    size_t numVertices;
    Vector vec; // Vector<Vector<>>
};


AdjListGraph *new_adjListGraph(size_t vertices){
    AdjListGraph* gr = malloc(sizeof(AdjListGraph));
    gr->numVertices = vertices;
    gr->vec = new_vector(sizeof(Vector), vertices);
    for (size_t i = 0; i < vertices; i++)
    {
        *((Vector*)get_vector(&gr->vec, i)) = new_vector(sizeof(struct Edges), 5);
    }
    return gr;
}

bool add_direct_edge(AdjListGraph* graph, size_t from_vertix, size_t to_vertix, size_t weight){
    if(graph == NULL) return NULL;

    if(to_vertix >= graph->numVertices || from_vertix >= graph->numVertices) 
        return false;

    struct Edges edge = { .vertix = to_vertix, .weight = weight };
    push_vector(((Vector*)get_vector(&graph->vec, from_vertix)), &edge);
    edge.vertix = from_vertix;
    push_vector(((Vector*)get_vector(&graph->vec, to_vertix)), &edge);
    return true;
}

#include <stdio.h>
void edgeFormat(const void *value){
    printf("{.weight=%ld, .vertix=%ld}, ", ((struct Edges*)value)->weight, ((struct Edges*)value)->vertix);
}

void debug_vectices(AdjListGraph *graph){
    if(graph == NULL ) return;
    for (size_t i = 0; i < graph->numVertices; i++)
    {
        printf("Vertix: %ld -> ", i);
        print_vector((Vector*)get_vector(&graph->vec, i), edgeFormat);
        printf("\n");
    }
    
}

void free_adjListGraph(AdjListGraph* graph){
    if(graph == NULL) return;
    for (size_t i = 0; i < graph->numVertices; i++)
    {
        free(((Vector*)get_vector(&graph->vec, i))->base);
    }
    free(graph->vec.base);
    free(graph);
}










