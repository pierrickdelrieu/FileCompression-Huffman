#include <stdio.h>
#include <stdlib.h>
#include "../../include/DataStructures/LinkedList.h"
#include "../../include/IHMCompressor/Show.h"


HuffmanNode *createHuffmanNode(int letter, int occ) {
    HuffmanNode *huff = NULL;
    huff = (HuffmanNode *) malloc(sizeof(HuffmanNode));

    if (huff != NULL) {
        huff->letter = letter;
        huff->occ = occ;
        huff->left = NULL;
        huff->right = NULL;
        return huff;
    } else {
        displayErrorMemoryAllocation();
    }
    return NULL;
}



Node *createNode(HuffmanNode *huffmanNode) {

    Node *newNode = NULL;
    newNode = (Node *) malloc(sizeof(Node));

    if (newNode != NULL) {
        newNode->data = huffmanNode;
        newNode->next = NULL;
        return newNode;
    } else {
        displayErrorMemoryAllocation();
    }
    return NULL;
}


void addNode(LinkedList *list, Node *node) {

    if (*list == NULL) {
        *list = node;
    } else {
        LinkedList temp = *list;

        while (temp->next != NULL) {
            temp = temp->next; // Here 'right' is working as temp->next
            // 'left' works as temp->prev
        }

        temp->next = node;
    }
}


void removeNode(LinkedList *list, HuffmanNode *huffmanNode) {

    LinkedList temp = *list;
    LinkedList previous = NULL;

    if (temp != NULL) {

        if (huffmanNode == NULL) {
            printf("\nCannot delete an empty node.");
        } else if (temp->data == huffmanNode) { // That means deleting the head
            *list = temp->next;
            free(temp);
            return;
        } else {
            while (temp != NULL && temp->data != huffmanNode) {
                previous = temp;
                temp = temp->next;
            }

            if (temp != NULL) {
                previous->next = temp->next;
                free(temp);
            } else {
                return;
            }
        }
    } else {
        printf("\nCannot remove anything from an empty list...");
    }
}


Node *find(LinkedList list, int letter) {
    if (list != NULL) {
        Node *temp = list;
        HuffmanNode *search = NULL;

        while (temp != NULL) {
            search = temp->data;

            if (search->letter == letter) {
                return temp;
            }

            temp = temp->next;
        }
    } else {
        printf("\nCannot search for a letter in an empty list");
    }

    return NULL;
}


int getSize(LinkedList list) {
    if (list == NULL) {
        return 0;
    } else {
        return 1 + getSize(list->next);
    }
}

Node* findMinOccLetter(Node* list) {       
    if (list != NULL) {
        Node* min = list;             

        while (list != NULL) {
            if (list->data->occ < min->data->occ) {  
                min = list;
            }
            list = list->next;
        }
        return min;

    }
    else {
        return NULL;
    }

}

void freeNode(LinkedList list) {
    if (list != NULL) {
        freeNode(list->next);
        free(list);
    }
}