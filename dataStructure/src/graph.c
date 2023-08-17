#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

graph_t* graphInit(){
    graph_t* node = (graph_t*)malloc(sizeof(graph_t));
    node->data = NULL;
    node->edges = NULL;
    node->edgeSize = 0;
    return node;
}

bool insertGraph(graph_t** _graph, void* _data){
    if(*_graph==NULL){
        *_graph = graphInit();
    }
    if((*_graph)->data == NULL){
        (*_graph)->data = _data;
        return true;
    }
    if((*_graph)->edgeSize==0){
        (*_graph)->edges = (graph_t**)malloc(sizeof(graph_t));
    }else{
        (*_graph)->edges = (graph_t**)realloc((*_graph)->edges, ((*_graph)->edgeSize + 1) *sizeof(graph_t));
    }
    (*_graph)->edgeSize++;
    (*_graph)->edges[(*_graph)->edgeSize-1] = graphInit();
    (*_graph)->edges[(*_graph)->edgeSize-1]->data = _data;
    return true;
}

bool freeGraph(graph_t* node){
    if(node==NULL){
        return false;
    }
    for(int i=0;i<node->edgeSize;i++){
        freeGraph(node->edges[i]);
    }
    free(node->edges);
    free(node);
    return true;
}