#include "graph.h"
#include <stdio.h>

graph_t* graphInit(void* _data){
    graph_t* node = (graph_t*)malloc(sizeof(graph_t));
    node->data = _data;
}