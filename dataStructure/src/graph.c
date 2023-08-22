#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct graphNode
{
    // data as void*?
    void* data;
    // Need limited vertices that points to a node
    struct graphNode** edges;
    int edgeSize;
}graphNode_t;

graph_t* graphInit(){
    graph_t* _graph = (graph_t*)malloc(sizeof(graph_t));
    if(_graph == NULL){
        printf("Not allocated graphInit()");
    }
    _graph->vertices = NULL;
    _graph->vertexSize = 0;
    return _graph;
}

graphNode_t* createGraphNode(void* _data){
    graphNode_t* _node = (graphNode_t*)malloc(sizeof(graphNode_t));
    if(_node == NULL){
        printf("Not allocated createGraphNode()");
    }
    _node->data = _data;
    _node->edges = NULL;
    _node->edgeSize = 0;
    return _node;
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
    node->edges = NULL;
    free(node);
    node = NULL;
    return true;
}