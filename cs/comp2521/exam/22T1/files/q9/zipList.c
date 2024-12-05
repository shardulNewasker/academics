
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

// Worst case time complexity of this solution: O(m + n)
static List MakeList(List l);
static int listSize(List l);
List zipList(List l1, int x, List l2, int y) {
    // TODO
    if (l2->first == NULL && x > 0) {
        return MakeList(l1);
    } else if (l1->first == NULL && y > 0) {
        return MakeList(l2);
    }
    if (x == 0 && y == 0) {
        return NULL;
    } else if (x <= 0 && y > 0) {
        return MakeList(l2);
    } else if (y <= 0 && x > 0) {
        return MakeList(l1);
    }
    // at this point both x, y > 0

    List l3 = ListNew();
    int size1 = listSize(l1);
    int size2 = listSize(l2);
    struct node *curr1 = l1->first;
    struct node *curr2 = l2->first;
    struct node *prev = NULL;
    struct node *new = NULL;
    int i = 0;
    while (i < size1 + size2) { // O(m + n)
        // add 'x' amt of l1
        int l1_added = 0;
        while (l1_added < x && curr1 != NULL) {
            new = newNode(curr1->value);
            if (prev != NULL) {
                prev->next = new;
            } else {
                l3->first = new;
            }
            prev = new;
            i++;
            l1_added++;
            curr1 = curr1->next;
        }

        // add 'y' amt of l2
        int l2_added = 0;
        while (l2_added < y && curr2 != NULL) {
            new = newNode(curr2->value);
            prev->next = new;
            prev = new;
            i++;
            l2_added++;
            curr2 = curr2->next;
        }
    }
    l3->last = prev;

    return l3;
}

static List MakeList(List l) {
    struct node *curr = l->first;
    struct node *prev = NULL;
    List newList = ListNew();
    while (curr != NULL) {
        struct node *new = newNode(curr->value);
        if (prev != NULL) {
            prev->next = new;
        } else {
            newList->first = new;
        }
        prev = new;
        curr = curr->next;
    }
    newList->last = prev;

    return newList;
}

static int listSize(List l) {
    int result = 0;
    struct node *curr = l->first;
    while (curr != NULL) {
        result++;
        curr = curr->next;
    }
    return result;
}