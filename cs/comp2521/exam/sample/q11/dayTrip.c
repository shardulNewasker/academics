
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
static bool exists(int val, Vertex vs[], int size) {
    for (int i = 0; i < size; i++) {
        if (vs[i] == val) {
            return true;
        }
    }
    return false;
}

int dayTrip(Graph g, Vertex s, Vertex vs[]) {
    // TODO
    //Vertex *arr = vs;
    int index = 0;
    //int black = 0;
    int nV = g->nV;

    // black roads
    for (int i = 0; i < nV; i++) {
        bool inArray = exists(i, vs, index);
        if (!inArray && g->stdEdges[s][i] == true) {
            vs[index] = i;
            index++;
            //black++;
        }
    }
    //int x = 0;
    //int y = 0;

    // red roads O(n^2)
    
    for (int i = 0; i < nV; i++) {
        bool inArray = exists(i, vs, index);

        if (g->fastEdges[s][i] == true) {
            if (!inArray) {
                vs[index] = i;
                index++;
            }
            for (int j = 0; j < nV; j++) {
                inArray = exists(j, vs, index);
                if (!inArray && g->fastEdges[i][j] == true && j != s) {
                    vs[index] = j;
                    index++;
                }
            }
        }
    }
    
    return index;
}

