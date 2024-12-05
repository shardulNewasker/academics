
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "BSTree.h"
void preOrder(BSTree t, int len, int *count, int *currPath);
int leafCount(BSTree t, int pathLength) {
    // TODO
    int count = 0;
    int currPath = 0;
    preOrder(t, pathLength, &count, &currPath);
    return count;
}
void preOrder(BSTree t, int len, int *count, int *currPath) {
    if (t == NULL) {
        (*currPath)--;
        return;
    }
    // node
    if (*currPath >= len && (t->left == NULL && t->right == NULL)) {
        (*count)++;
        //printf("Here at node %d\n", t->key);
    }
    //left
    (*currPath)++;
    preOrder(t->left, len, count, currPath);
    //right
    (*currPath)++;
    preOrder(t->right, len, count, currPath);

    (*currPath)--;
    return;
}


