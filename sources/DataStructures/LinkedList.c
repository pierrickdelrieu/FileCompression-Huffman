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
    if (list != NULL) {
        Node* del = find(*list, letter);

        if (del != NULL) {

            if (del == *list) {
                Node* temp = (*list)->right;
                *list = temp;
                free(temp);
            }

            else {
                Node* before = del->left;
                Node* next = del->right;

                before->right = next;
                next->left = before;
                free(del);
            }
        }

        else {
            printf("\nCouldn't remove '%c' from the list as it wasn't in it", letter);
        }
    }

    else {
        printf("\nCannot remove a letter from an empty list");
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
