#include "./AdjacencyMatrix.h"
#include "../Vector/Vector.h"
#include <stdio.h>
#include <string.h>


AdjMatrixGraph* new_graph_matrix(size_t nodeCount){
    AdjMatrixGraph *graph = malloc(sizeof(AdjMatrixGraph));

    graph->matrix = malloc(sizeof(bool*) * nodeCount);
    memset(graph->matrix, 0, sizeof(bool*) * nodeCount);
    
    for (size_t i = 0; i < nodeCount; i++)
    {
        graph->matrix[i] = malloc(sizeof(bool) * nodeCount);
        memset(graph->matrix[i], 0, sizeof(bool) * nodeCount);

    }
    graph->nodeCount = nodeCount;
    return graph;
}

bool to_edge(AdjMatrixGraph* graph, size_t from, size_t to){
    if(graph == NULL && graph->matrix == NULL) return false;
    if (from > graph->nodeCount || to > graph->nodeCount) return false;
    
    graph->matrix[from][to] = true;
    return true;
}

bool disconnect_edge(AdjMatrixGraph* graph, size_t from, size_t to){
    if(graph == NULL && graph->matrix == NULL) return false;
    if (from > graph->nodeCount || to > graph->nodeCount) return false;
    
    graph->matrix[from][to] = false;
    return true;
}

bool has_edge(AdjMatrixGraph* graph, size_t from, size_t to){
    if(graph == NULL && graph->matrix == NULL) return false;
    if (from > graph->nodeCount || to > graph->nodeCount) return false;
    return graph->matrix[from][to];
}

void matrix_dfs(AdjMatrixGraph* graph, size_t starting){
    int len = graph->nodeCount;
    bool traveled[len];
    memset(traveled, 0, sizeof(traveled));
    Vector vec = Init_Vector(sizeof(size_t),10);

    
    push(&vec, &starting);
        

    size_t catch;
    while (pop(&vec,&catch))
    {   
        if (traveled[catch])
        {
            continue;
        }
        
        // Mark as visited
        traveled[catch] = true;

        // Process the current node (e.g., print it)
        printf("%ld ", catch);

        // Push all unvisited neighbors onto the stack
        for (size_t i = 0; i < len; i++) {
            if (graph->matrix[catch][i] && !traveled[i]) {
                push(&vec, &i);
            }
        }
    }
    
    

    
    free(vec.base);
}

void print_graph_table(AdjMatrixGraph *graph){
    for (size_t i = 0; i < graph->nodeCount; i++)
    {
        for (size_t j = 0; j < graph->nodeCount; j++)
        {
            printf("%d ", graph->matrix[j][i]);
        }
        printf("\n");
    }
}

void free_graph(AdjMatrixGraph *graph){
    for (size_t i = 0; i < graph->nodeCount; i++)
    {
        free(graph->matrix[i]);
    }
    free(graph->matrix);
    free(graph);
}






int main(int argc, char const *argv[])
{
    AdjMatrixGraph *gr = new_graph_matrix(10);

    to_edge(gr, 5, 7);
    to_edge(gr, 7, 3);
    to_edge(gr, 5, 1);
    to_edge(gr, 5, 7);
    to_edge(gr, 1, 3);
    to_edge(gr, 7, 2);
    to_edge(gr, 3, 0);
    to_edge(gr, 5, 5);
    to_edge(gr, 6, 9);

    matrix_dfs(gr, 5);

    printf("\n");
    print_graph_table(gr);

    return 0;
}

