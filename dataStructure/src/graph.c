#include "graph.h"
#include <stdio.h>

graph_t* graphInit(){
    graph_t* node = (graph_t*)malloc(sizeof(graph_t));
    node->data = NULL;
    node->edges = NULL;
}

bool insertGraph(graph_t* _graph, void* _data){
    
}

bool freeGraph(graph_t* node){
    free(node);
}