#ifndef ADJACENCY_MATRIX_H
#define ADJACENCY_MATRIX_H

#include <stdio.h>

typedef struct AdjMatrix{
    size_t nodeCount;
    bool **matrix;
} AdjMatrixGraph;

AdjMatrixGraph* new_graph_matrix(size_t nodeCount);

bool to_edge(AdjMatrixGraph* graph, size_t from, size_t to);
bool has_edge(AdjMatrixGraph* graph, size_t from, size_t to);

bool matrix_dfs(AdjMatrixGraph* graph);

#endif