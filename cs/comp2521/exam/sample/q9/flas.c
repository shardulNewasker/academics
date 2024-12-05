
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

struct node *flas(struct node *l) {
    // TODO
    // O(n^2)
    if (l == NULL) {
        return l;
    } else if (l->next == NULL) {
        return l;
    }
    // atp size >= 2
    struct node *start = NULL;
    struct node *curr_out = l;
    struct node *curr_in = NULL;
    struct node *prev = NULL;
    int max = 0;
    int count = 0;

    for (; curr_out != NULL; curr_out = curr_out->next) {
        count = 0;
        prev = NULL;
        for (curr_in = curr_out; curr_in != NULL; curr_in = curr_in->next) {
            if (prev != NULL && prev->value < curr_in->value) {
                count++;
            } else if (prev != NULL && prev->value >= curr_in->value) {
                break;
            }
            prev = curr_in;
        }
        if (count > max) {
            start = curr_out;
            max = count;
        }
    }

    return start;
}

