#ifndef ADJACENCY_LIST_H_
#define ADJACENCY_LIST_H_

#include <stdbool.h>
#include <stdlib.h>

typedef struct AdjListGraph AdjListGraph;

AdjListGraph *new_adjListGraph(size_t vertices);

bool add_direct_edge(AdjListGraph* graph, size_t from_vertix, size_t to_vertix, size_t weight);
bool add_undirect_edge(AdjListGraph* graph, size_t from_vertix, size_t to_vertix, size_t weight);



bool remove_edge(AdjListGraph* graph, size_t from_vertix, size_t to_vertix);


void debug_vectices(AdjListGraph *graph);
void free_adjListGraph(AdjListGraph* graph);


#endif