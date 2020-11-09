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
 * @param f Queue address initialized Queue initialized (modified data)
 */
void initQueue(Queue** f) {
    *f = (Queue*) malloc(sizeof(Queue));
    (*f)->start = NULL;
    (*f)->end = NULL;
}


/**
 * @brief Adding an node to the top of the list
 * 
 * @param f Queue adress (modified data) where the node must be added
 * @param nx_elem Node to add at the top of the list
 * @return int Return 1 if node has been added and 0 otherwise (if the Queue has not been initialized)
 */
int pushQueue(Queue** f, Node* nx_elem) {
    // If the Queue has been initialized
    if (f != NULL) {

        // If the Queue is not empty
        if (((*f)->start == NULL) && ((*f)->end == NULL)) {
            (*f)->start = nx_elem;
            (*f)->end = nx_elem;
            return 1;
        }

        // If the Queue already contains nodes
        else {
            Node *temp = (*f)->start;
            (*f)->start = nx_elem;
            nx_elem->right = temp;
            return 1;
        }
    }
    
    // If the Queue has not been initialized
    return 0;
}


/**
 * @brief Remove and return the last element in the Queue
 * 
 * @param f Queue adress (modified data) where the node must be removed
 * @return Node* Removed node
 */
Node* pullQueue(Queue** f) {
    // If the Queue has been initialized
    if(f != NULL) {
        Node* temp = (*f)->start;

        // If the Queue contains one or zero node
        if((*f)->start == (*f)->end){
            (*f)->start = NULL;
            (*f)->end = NULL;
            return temp;
        }

        // If the Queue contains several nodes
        else {
            Node* ptrprec = NULL;

            // Placement at the last and penultimate node of the list
            while (temp->right != NULL) {
                ptrprec = temp;
                temp = temp->right;
            }

            (*f)->end = ptrprec;
            (*f)->end->right = NULL;
            return temp;
        }
    }

    // If the Queue has not been initialized
    return NULL;
}