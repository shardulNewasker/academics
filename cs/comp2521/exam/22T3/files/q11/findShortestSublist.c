
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"
/**
 * 1. Make a linked list that stores all indexes where l->val == start
 *     - repeat same for when l->val == end
 * 2. get the shortest length'd index for both in O(n) time.
 */
List findShortestSublist(List l, int start, int end) {
   // TODO
    List startIndex = ListNew();
    struct node *curr = l->first;
    struct node *prev = NULL;
    int i = 0;

    while (curr != NULL) {
        if (curr->value == start) {
            struct node *new = newNode(i);
            if (prev == NULL) {
                startIndex->first = new;
            } else {
                prev->next = new;
            }
            prev = new;
        }
        curr = curr->next;
        i++;
    }

    i = 0;
    curr = l->first;
    prev = NULL;
    List endIndex = ListNew();
    while (curr != NULL) {
        if (curr->value == end) {
            struct node *new = newNode(i);
            if (prev == NULL) {
                endIndex->first = new;
            } else {
                prev->next = new;
            }
            prev = new;
        }
        curr = curr->next;
        i++;
    }

    int size = i;
    int min = size + 1;
    int s = 0;
    int e = 0;
    struct node *l1 = startIndex->first;
    struct node *l2 = endIndex->first;
    if (l1 == NULL || l2 == NULL) {
        while (startIndex->first != NULL) {
        struct node *temp = startIndex->first->next;
        free(startIndex->first);
        startIndex->first = temp;
        } while (endIndex->first != NULL) {
        struct node *temp = endIndex->first->next;
        free(endIndex->first);
        endIndex->first = temp;
    }
        return NULL;
    }
    while (l2 != NULL) { // O(n1) + O(n2) <= O(n)
        int closestToEnd = -1;
        if (l1->value < l2->value) {
            while(l1 != NULL && l1->value <= l2->value) {
                closestToEnd = l1->value;
                l1 = l1->next;
            }
        }
        int diff = l2->value - closestToEnd;

        if (diff < min) {
            min = diff;
            s = closestToEnd;
            e = l2->value;
        }

        l2 = l2->next;
    }

    curr = l->first;
    int newSize = 0;
    struct node *startNode = NULL;
   // struct node *endNode = NULL;
    for (int j = 0; j < size; j++) {
        if (j == s) {
            startNode = curr;
        }

        if (j >= s && j <= e) {
            newSize++;
        }

        if (j == e) {
            //endNode = curr;
            break;
        }
        curr = curr->next;
    }

    List result = ListNew();
    prev = NULL;
    for (int j = 0; j < newSize && startNode != NULL; j++) {
        struct node *new = newNode(startNode->value);
        if (prev != NULL) {
            prev->next = new;
        } else {
            result->first = new;
        }
        prev = new;
        startNode = startNode->next;
    }
    result->last = prev;

    while (startIndex->first != NULL) {
        struct node *temp = startIndex->first->next;
        free(startIndex->first);
        startIndex->first = temp;
    } while (endIndex->first != NULL) {
        struct node *temp = endIndex->first->next;
        free(endIndex->first);
        endIndex->first = temp;
    }

    return result;
}

