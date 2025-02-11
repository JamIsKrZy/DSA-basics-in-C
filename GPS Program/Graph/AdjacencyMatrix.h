#ifndef ADJACENCY_MATRIX_H
#define ADJACENCY_MATRIX_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct AdjMatrix{
    size_t nodeCount;
    bool **matrix;
} AdjMatrixGraph;

AdjMatrixGraph* new_graph_matrix(size_t nodeCount);

bool connect_edge(AdjMatrixGraph* graph, size_t node1, size_t node2);
bool direct_edge(AdjMatrixGraph* graph, size_t from, size_t to);
bool remove_direct_edge(AdjMatrixGraph* graph, size_t from, size_t to);
bool has_edge(AdjMatrixGraph* graph, size_t from, size_t to);

void matrix_dfs(AdjMatrixGraph* graph, size_t starting);
void print_graph_table(AdjMatrixGraph *graph);

void free_graph(AdjMatrixGraph *graph);

#endif