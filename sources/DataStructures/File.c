/**
 * @file File.c
 * @author Pierrick Delrieu
 * @brief Management of the linked list with a file
 * @version 0.1
 * @date 07-11-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "../../include/DataStructures/File.h"


/**
 * @brief Initialization of the start and end fields of the fiel (queue) and memory allocation
 * 
 * @param f File (queue) address initialized file initialized (modified data)
 */
void initFile(File** f) {
    *f = (File*) malloc(sizeof(File));
    (*f)->start = NULL;
    (*f)->end = NULL;
}


/**
 * @brief Adding an node to the top of the list
 * 
 * @param f File (queue) adress (modified data) where the node must be added
 * @param nx_elem Node to add at the top of the list
 * @return int Return 1 if node has been added and 0 otherwise (if the file (queue) has not been initialized)
 */
int enfiler(File** f, Node* nx_elem) {
    // If the file (queue) has been initialized
    if (f != NULL) {

        // If the file (queue) is not empty
        if (((*f)->start == NULL) && ((*f)->end == NULL)) {
            (*f)->start = nx_elem;
            (*f)->end = nx_elem;
            return 1;
        }

        // If the file (queue) already contains nodes
        else {
            Node *temp = (*f)->start;
            (*f)->start = nx_elem;
            nx_elem->right = temp;
            return 1;
        }
    }
    
    // If the file (queue) has not been initialized
    return 0;
}


/**
 * @brief Remove and return the last element in the file (queue)
 * 
 * @param f File (queue) adress (modified data) where the node must be removed
 * @return Node* Removed node
 */
Node* defiler(File** f) {
    // If the file (queue) has been initialized
    if(f != NULL) {
        Node* temp = (*f)->start;

        // If the file (queue) contains one or zero node
        if((*f)->start == (*f)->end){
            (*f)->start = NULL;
            (*f)->end = NULL;
            return temp->letter;
        }

        // If the file (queue) contains several nodes
        else {
            Node* ptrprec = NULL;

            // Placement at the last and penultimate node of the list
            while (temp->right != NULL) {
                ptrprec = temp;
                temp = temp->right;
            }

            (*f)->end = ptrprec;
            (*f)->end->right = NULL;
            return temp->letter;
        }
    }

    // If the file (queue) has not been initialized
    return NULL;
}