#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

typedef struct graph
{
    // data as void*?
    void* data;
    // Need limited vertices that points to a node
    struct graph* edges;
}graph_t;

// Initialize graph
graph_t* graphInit();

bool insertGraph(graph_t* _graph, void* _data);

// Free graph
bool freeGraph(graph_t* node);

#endif