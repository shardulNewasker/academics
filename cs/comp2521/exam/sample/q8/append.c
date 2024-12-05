
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

// WARNING: while loops, for loops, do loops and goto statements are
//          strictly forbidden.
struct node *append(struct node *l1, struct node *l2) {
    // TODO
    if (l1 == NULL) {
        return l2;
    } 
    if (l1->next == NULL) {
        l1->next = l2;
        return l1;
    }
    struct node *newHead = l1;
    newHead->next = append(l1->next, l2);
    return newHead;
}

