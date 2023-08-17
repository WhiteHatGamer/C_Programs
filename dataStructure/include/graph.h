#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

typedef struct graph
{
    // data as void*?
    void* data;
    // Need limited vertices that points to a node
    struct graph** edges;
    int edgeSize;
}graph_t;

// Initialize graph
graph_t* graphInit();

// Insert data into graph
bool insertGraph(graph_t** _graph, void* _data);

// Delete from Node
bool graphDeleteNode(graph_t** _graph, void* _data);

// Search from Graph

// print graph Data

// Free graph
bool freeGraph(graph_t* node);

#endif