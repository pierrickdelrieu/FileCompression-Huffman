/**
 * @file File.c
 * @author Pierrick Delrieu
 * @brief Management of the linked list with a Queue
 * @version 0.1
 * @date 07-11-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "../../include/DataStructures/Queue.h"


/**
 * @brief Initialization of the last and first fields of the fiel and memory allocation
 * 
 * @return Queue* address initialized Queue initialized
 */
Queue *initQueue(void) {
    Queue *f = NULL;
    f = (Queue *) malloc(sizeof(Queue));
    f->last = NULL;
    f->first = NULL;
    return f;
}


/**
 * @brief Adding an HuffmanNode to the top of the list
 * 
 * @param f Queue adress (modified data) where the HuffmanNode must be added
 * @param nx_elem HuffmanNode to add at the top of the list
 * @return int Return 1 if HuffmanNode has been added and 0 otherwise (if the Queue has not been initialized)
 */
int pushQueue(Queue **f, HuffmanNode *nx_elem) {

    // If the Queue has been initialized
    if (f != NULL) {
        Node *x = createNode(nx_elem);

        // If the Queue is not empty
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


/**
 * @brief Remove and return the last element in the Queue
 * 
 * @param f Queue adress (modified data) where the HuffmanNode must be removed
 * @return HuffmanNode* Removed HuffmanNode
 */
HuffmanNode *pullQueue(Queue **f) {
    // If the Queue has been initialized
    if (f != NULL) {
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

    // If the Queue has not been initialized
    return NULL;
}

Queue* sortList(Node** list) {
    // list not empty
    if (*list != NULL) {
        int nb = 0;                     // security on pushQueue
        Node* min = NULL;               // Node with least occurrences
        Node* prec = NULL;              // Previous Node of min
        Queue* f = initQueue();         // Queue to return
        int size = getSize(*list);      // size of list to do a loop.
        int i = 0;                      // counter

        // Repeat process size times to go through whole list
        for (i = 0; i < size; i++) {

            // prec always initialised to first node and min is being searched
            prec = *list;
            min = findMinOccLetter(*list);

            // Node with least occurrences is the first one
            if (prec == min) {
                *list = (*list)->next;
                nb = pushQueue(&f, min->data);

                // go through list to find previous Node of min
            }
            else {
                while (prec->next != min) {
                    prec = prec->next;
                }

                // connect previous Node to the one after min and enqueue min
                prec->next = min->next;
                nb = pushQueue(&f, min->data); // don't know how to use it though
            }
        }
        return f;

        // list is empty
    }
    else {
        return NULL;
    }
}