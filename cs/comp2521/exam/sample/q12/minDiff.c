
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

static void preOrder(struct node *t, int l, int *currLevel, int *arr, int *index);
static int power(int a, int b);

int minDiff(struct node *t, int l) {
    // TODO
    if (l == 0 || (t->left == NULL && t->right == NULL)) {
        return 0;
    }
    int maxSize = power(2, l);
    int *arr = calloc(maxSize, sizeof(int));
    int currLevel = 0;
    int index = 0;
    preOrder(t, l, &currLevel, arr, &index);
    if (index <= 1) {
        free(arr);
        return 0;
    }
    int min = 1000000;
    // for (int i = 0; i < index; i++) {
    //     printf(" %d ", arr[i]);
    // }
    for (int i = 0; i + 1 < index; i++) {
        int res = abs(arr[i] - arr[i + 1]);
        if (res <= min) {
            min = res;
        }
    }
    free(arr);
    return min;
}

static void preOrder(struct node *t, int l, int *currLevel, int *arr, int *index) {
    if (t == NULL) {
        (*currLevel)--;
        return;
    }
    // visit t
    if ((*currLevel) == l) {
        arr[*index] = t->key;
        (*index)++;
        //return;
    }

    (*currLevel)++;
    preOrder(t->left, l, currLevel, arr, index);

    (*currLevel)++;
    preOrder(t->right, l, currLevel, arr, index);
    
    (*currLevel)--; // <--- important part ?
    return;
}

static int power(int a, int b) {
    if (b == 0) {
        return 1;
    }
    for (int i = 1; i < b; i++) {
        a *= a;
    }
    return a;
}