#include <stdio.h>
#include <stdlib.h>
#include "../../include/DataStructures/Queue.h"



Queue *initQueue(void) {
    Queue *f = NULL;
    f = (Queue *) malloc(sizeof(Queue));
    f->last = NULL;
    f->first = NULL;
    return f;
}



int pushQueue(Queue **f, HuffmanNode *nx_elem) {

    // If the Queue has been initialized
    if (f != NULL) {
        Node *x = createNode(nx_elem);

        // If the Queue is empty
        if (((*f)->last == NULL) && ((*f)->first == NULL)) {
            (*f)->last = x;
            (*f)->first = x;
            return 1;
        }

            // If the Queue already contains HuffmanNodes
        else {
            Node *temp = (*f)->last;
            (*f)->last = x;
            x->next = temp;
            return 1;
        }
    }

    // If the Queue has not been initialized
    return 0;
}



HuffmanNode *pullQueue(Queue **f) {
    // If the Queue has been initialized
    if (f != NULL) {
        if (((*f)->first != NULL) && ((*f)->last != NULL)) {
            Node *temp = (*f)->last;

            // If the Queue contains one or zero HuffmanNode
            if ((*f)->last == (*f)->first) {
                (*f)->last = NULL;
                (*f)->first = NULL;
                return temp->data;
            }

                // If the Queue contains several HuffmanNodes
            else {
                Node *ptrprec = NULL;

                // Placement at the last and penultimate HuffmanNode of the list
                while (temp->next != NULL) {
                    ptrprec = temp;
                    temp = temp->next;
                }

                (*f)->first = ptrprec;
                (*f)->first->next = NULL;
                return temp->data;
            }
        }
    }

    // If the Queue has not been initialized
    return NULL;
}
