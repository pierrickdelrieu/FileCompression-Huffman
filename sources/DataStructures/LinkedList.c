#include <stdio.h>
#include <stdlib.h>
#include "../../include/DataStructures/LinkedList.h"
#include "../../include/IHMCompressor/Show.h"

Node* createNode(int letter, int occ) {

    Node* newNode = (Node*) malloc(sizeof(Node));

    if (newNode != NULL) {
        newNode->letter = letter;
        newNode->occ = occ;

        return newNode;
    }

    else {
        displayErrorMemoryAllocation();
    }
}

void addNode(LinkedList* list, Node* node) {

    if (*list == NULL) {
        *list = node;
    }

    else {
        LinkedList temp = *list;

        while (temp->right != NULL) {
            temp = temp->right; // Here 'right' is working as temp->next
        }

        temp->right = node;
        node->left = temp;
    }
}

void removeNode(LinkedList* list, int letter) {

    Node *del = find(*list, letter);


    if (*list == NULL || del == NULL) { // Why try and delete a node from a list that doesn't exists ?
        printf("\nCannot remove anything from an empty list");
        return;
    }

    else {

        if (*list == del) { // If we need to delete the head
            *list = del->right;
        }

        if (del->right != NULL) { // Only if we don't delete the last node of the list
            del->right->left = del->right;
        }

        if (del->left != NULL) { // Only if we don't delete the first node of the list
            del->left->right = del->right;
        }

        free(del); // Then we free del
    }
}

Node* find(LinkedList list, int letter) {
    if (list != NULL) {
        Node* temp = list;

        while (temp != NULL) {
            if (temp->letter == letter) {
                return temp;
            }

            temp = temp->right;
        }

        return NULL;
    }

    else {
        printf("\nCannot search for a letter in an empty list");
    }
}

int getSize(LinkedList list) {
    if (list == NULL) {
        return 0;
    }

    else {
        return 1 + getSize(list->right);
    }
}

void printList(LinkedList list) {
    if (list != NULL) {
        printf("\nLetter '%c' present %d times ", list->letter, list->occ);
        printList(list->right);
    }
}
