#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct graphNode
{
    // data as void*?
    void* data;
    // Need limited vertices that points to a node
    struct graphNode** edges;
    int edgeSize;
}graphNode_t;

bool freeGraphNode(graphNode_t** _node);

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

bool insertGraphVertex(graph_t** _graph, void* _data){
    if(*_graph==NULL){
        *_graph = graphInit();
    }
    if((*_graph)->vertices == NULL){
        (*_graph)->vertices = (graphNode_t**)malloc(sizeof(graphNode_t*));
        if((*_graph)->vertices == NULL){
            printf("Not allocated insertGraphVertex()");
    }
    }else{
        (*_graph)->vertices = (graphNode_t**)realloc((*_graph)->vertices, ((*_graph)->vertexSize + 1) *sizeof(graphNode_t*));
        if((*_graph)->vertices == NULL){
            printf("Not allocated insertGraphVertex()");
        }
    }
    (*_graph)->vertices[(*_graph)->vertexSize] = createGraphNode(_data);
    (*_graph)->vertexSize++;
    return true;
}


bool addGraphNodeEdge(graphNode_t* tmpFrom,graphNode_t* tmpTo){
    if((tmpFrom)->edges == NULL){
        (tmpFrom)->edges = (graphNode_t**)malloc(sizeof(graphNode_t*));
        if((tmpFrom)->edges == NULL){
            printf("Not allocated insertGraphNodeEdge()");
        }
    }else{
        for(int i=0;i<tmpFrom->edgeSize;i++){
            if(tmpFrom->edges[i] == tmpTo){
                // Edge Already there 
                return false;
            }
        }
        (tmpFrom)->edges = (graphNode_t**)realloc((tmpFrom)->edges, ((tmpFrom)->edgeSize + 1) *sizeof(graphNode_t*));
        if((tmpFrom)->edges == NULL){
            printf("Not allocated insertGraphNodeEdge()");
        }
    }
    (tmpFrom)->edges[(tmpFrom)->edgeSize] = tmpTo;
    (tmpFrom)->edgeSize++;
    return true;
}

bool addGraphEdges(graph_t** _graph, void* _fromData, void* _toData){
    if((*_graph) == NULL){
        insertGraphVertex(_graph, _fromData);
    }
    graphNode_t* tmpFrom,* tmpTo;
    tmpFrom = tmpTo = NULL;
    for(int i=0;i<(*_graph)->vertexSize;i++){
        if((*_graph)->vertices[i]->data == _fromData){
            tmpFrom = (*_graph)->vertices[i];
        }else if ((*_graph)->vertices[i]->data == _toData){
            tmpTo = (*_graph)->vertices[i];
        }
    }
    if(tmpFrom == NULL){
        // Data not in graph
        insertGraphVertex(_graph, _fromData);
        tmpFrom = (*_graph)->vertices[(*_graph)->vertexSize-1];
    }else if(tmpTo == NULL){
        insertGraphVertex(_graph, _toData);
        tmpTo = (*_graph)->vertices[(*_graph)->vertexSize-1];
    }
    return addGraphNodeEdge(tmpFrom, tmpTo);
}


bool printGraphNode(graphNode_t* _node){
    if(_node == NULL){
        return false;
    }
    printf("%p\n", _node->data);
    for(int i=0;i<_node->edgeSize;i++){
        printf("|--->%p\n", _node->edges[i]->data);
        // printGraphNode(_node->edges[i]);
    }
    return true;
}

bool printGraph(graph_t* _graph){
    if(_graph == NULL){
        return false;
    }
    printf("\n---------------------------------\n");
    for(int i=0;i<_graph->vertexSize;i++){
        printGraphNode(_graph->vertices[i]);
    }
    printf("\n---------------------------------\n");
    // if(printGraphRec(_graph, 0)){
    //     return true;
    // }
    return true;
}


bool freeGraphNode(graphNode_t** _node){
    if((*_node) == NULL){
        return false;
    }
    if((*_node)->edgeSize == 0){
        free((*_node));
        (*_node) = NULL;
        return true;
    }else{
        free((*_node)->edges);
        (*_node)->edges = NULL;
        free((*_node));
        (*_node) = NULL;
        return true;
    }
}

bool freeGraph(graph_t** _graph){
    if(*_graph==NULL){
        return false;
    }
    for(int i=0;i<(*_graph)->vertexSize;i++){
        freeGraphNode(&(*_graph)->vertices[i]);
    }
    if((*_graph)->vertices){
        free((*_graph)->vertices);
    }
    (*_graph)->vertices = NULL;
    free((*_graph));
    (*_graph) = NULL;
    return true;
}
