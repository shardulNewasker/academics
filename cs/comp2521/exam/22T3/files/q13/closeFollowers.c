
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

static void FreeProgram(int **tc, int *inDegree, int nV);
int **warshall(Graph g);    
void closeFollowers(Graph g, int src, int distance, int followers[]) {
    // TODO
    /**
     * 1. Make a tc Matrix that stores shortest distance from node A to node B. O(n^3)
     * 2. Store Each vertex's in degree. O(n^2)
     */
    int nV = g->nV;
    int **tc = warshall(g);
    int *inDegree = calloc(nV, sizeof(int));
    for (int i = 0; i < nV; i++) { // O(V^2)
        for (int j = 0; j < nV; j++) {
            // edge i --> j
            if (GraphIsAdjacent(g, i, j)) {
                inDegree[j]++;
            }
        }
    }
    for (int i = 0; i < nV; i++) {
        if ((i == src || tc[i][src] > 0) && tc[i][src] <= distance && inDegree[i] > 1) {
            //printf("Node: %d | Indeg: %d | Dist: %d\n", i, tc[i][src], inDegree[i]);
            followers[i] = 1;
        }
    }
    //printf("Node: %d | Indeg: %d | Dist: %d\n", 3, inDegree[3], tc[3][src]);
    FreeProgram(tc, inDegree, nV);
    return;
}
int **warshall(Graph g) {
    int nV = g->nV;
    int **tc = malloc(nV * sizeof(int *));
    for (int i = 0; i < nV; i++) {
        tc[i] = calloc(nV, sizeof(int));
    }
    // O(V^2)
    for (int i = 0; i < nV; i++) {
        for (int j = 0; j < nV; j++) {
            //printf("There is %d\n", tc[i][j]);
            tc[i][j] = g->edges[i][j];
        }
    }

    for (int k = 0; k < nV; k++) { // O(V^3)
        for (int s = 0; s < nV; s++) {
            for (int t = 0; t < nV; t++) {
                if (tc[s][k] > 0 && tc[k][t] > 0) {
                    int newDist = tc[s][k] + tc[k][t];
                    if (tc[s][t] == 0 || newDist <= tc[s][t]) {
                        tc[s][t] = newDist;
                    }
                }
            }
        }
    }

    return tc;
}

static void FreeProgram(int **tc, int *inDegree, int nV) {
    free(inDegree);
    for (int i = 0; i < nV; i++) {
        free(tc[i]);
    }
}