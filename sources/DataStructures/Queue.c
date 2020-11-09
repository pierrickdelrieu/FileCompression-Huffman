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
 * @brief Initialization of the start and end fields of the fiel and memory allocation
 * 
 * @return Queue* address initialized Queue initialized
 */
Queue* initQueue(void) {
    Queue* f = NULL;
    f = (Queue*) malloc(sizeof(Queue));
    f->start = NULL;
    f->end = NULL;
    return f;
}


/**
 * @brief Adding an HuffmanNode to the top of the list
 * 
 * @param f Queue adress (modified data) where the HuffmanNode must be added
 * @param nx_elem HuffmanNode to add at the top of the list
 * @return int Return 1 if HuffmanNode has been added and 0 otherwise (if the Queue has not been initialized)
 */
int pushQueue(Queue** f, HuffmanNode* nx_elem) {
    
    // If the Queue has been initialized
    if (f != NULL) {
        Node* x = createNode(nx_elem);

        // If the Queue is not empty
        if (((*f)->start == NULL) && ((*f)->end == NULL)) {
            (*f)->start = x;
            (*f)->end = x;
            return 1;
        }

        // If the Queue already contains HuffmanNodes
        else {
            Node *temp = (*f)->start;
            (*f)->start = x;
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
HuffmanNode* pullQueue(Queue** f) {
    // If the Queue has been initialized
    if(f != NULL) {
        Node* temp = (*f)->start;

        // If the Queue contains one or zero HuffmanNode
        if((*f)->start == (*f)->end){
            (*f)->start = NULL;
            (*f)->end = NULL;
            return temp->data;
        }

        // If the Queue contains several HuffmanNodes
        else {
            Node* ptrprec = NULL;

            // Placement at the last and penultimate HuffmanNode of the list
            while (temp->next != NULL) {
                ptrprec = temp;
                temp = temp->next;
            }

            (*f)->end = ptrprec;
            (*f)->end->next = NULL;
            return temp->data;
        }
    }

    // If the Queue has not been initialized
    return NULL;
}