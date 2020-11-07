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
#include "../../include/DataStructures/LinkedList.h"



void init_file(File** f) {
    *f = (File*) malloc(sizeof(File));
    (*f)->start = NULL;
    (*f)->end = NULL;
}


void enfiler(File** f, Node* nx_elem) {
    if (f != NULL) {

        if (((*f)->start == NULL) && ((*f)->end == NULL)) {
            (*f)->start = nx_elem;
            (*f)->end = nx_elem;
        }
        else {
            Node *temp = (*f)->start;
            (*f)->start = nx_elem;
            nx_elem->right = temp;
        }
    }
}


Node* defiler(File** f) {
    if(f != NULL) {
        Element* temp = (*f)->start;

        if((*f)->start == (*f)->end){
            (*f)->start = NULL;
            (*f)->end = NULL;
            return temp->data;
        }
        else {
            Element* ptrprec = NULL;
            while (temp->next != NULL) {
                ptrprec = temp;
                temp = temp->next;
            }

            (*f)->end = ptrprec;
            (*f)->end->next = NULL;
            return temp->data;
        }
    }
    return NULL;
}