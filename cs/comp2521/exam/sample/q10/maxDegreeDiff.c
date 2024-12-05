
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

struct degree {
    int in;
    int out;
    int diff;
};

int maxDegreeDiff(Graph g) {
    // TODO
    int nV = GraphNumVertices(g);
    struct degree *arr = calloc(nV, sizeof(*arr));

    for (int i = 0; i < nV; i++) {
        struct adjNode *node = g->edges[i];
        while (node != NULL) {
            arr[i].out++;
            arr[node->v].in++;
            node = node->next;
        }
    }
    
    for (int i = 0; i < nV; i++) {
        arr[i].diff = abs(arr[i].in - arr[i].out);
    }

    int max = -1;
    for (int i = 0; i < nV; i++) {
        if (arr[i].diff > max) {
            max = arr[i].diff;
        }
    }

    return max;
}

