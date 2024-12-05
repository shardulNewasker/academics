
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

// Worst case time complexity of this solution: O(...)
void nodesNotInCycle(Graph g, int notInCycle[]) {
    // TODO
    bool *visited = calloc(g->nV, sizeof(bool));
    bool *onStack = calloc(g->nV, sizeof(bool));
}
//void hasCycle()

void dfsHasCycle(Graph g, Vertex v, bool *visited, bool *onStack, int notInCycle[]) {
    visited[v] = true;
    onStack[v] = true;

    for (Vertex w = 0; w < g->nV; w++) {
        if (GraphIsAdjacent(g, v, w)) {
            if (visited[v] && onStack[v])
            dfsHasCycle(g, v, visited, onStack);
        }
    }
    onStack[v] = false;
    return;
}
