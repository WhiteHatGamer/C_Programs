#ifndef GRAPH_H
#define GRAPH_H

typedef struct graph
{
    // data as void*?
    void* data;
    // Need limited vertices that points to a node
    struct graph* edges;
}graph_t;

// Initialize graph
graph_t* graphInit();

#endif