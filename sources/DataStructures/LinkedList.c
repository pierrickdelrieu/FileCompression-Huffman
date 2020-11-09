/**
 * @file LinkedList.c
 * @author Benjamin Lesieux
 * @brief All the basic functions of a doubly linked list
 * @details Part 2 of project
 * @version 1.0
 * @date 09-11-20
 *
 * @copyright Copyright (c) 2020
 *
 */



#include <stdio.h>
#include <stdlib.h>
#include "../../include/DataStructures/LinkedList.h"
#include "../../include/IHMCompressor/Show.h"

/**
 *
 * @author Benjamin Lesieux
 *
 * @brief Creates a node for a doubly linked list
 * @param letter, an integer corresponding to the ascii value of the letter
 * @param occ, the number of occurrences of the letter
 *
 * @return Node*, A pointer to a Node
 * */
Node* createNode(int letter, int occ) {

    Node* newNode = NULL;
    newNode = (Node*) malloc(sizeof(Node));

    if (newNode != NULL) {
        newNode->letter = letter;
        newNode->occ = occ;
    }
    else {
        displayErrorMemoryAllocation();
    }

    return newNode;
}

/**
 *
 * @author Benjamin Lesieux
 *
 * @brief adds a Node to a Doubly Linked List
 * @param list, the head of the list (Node*)
 * @param node, a pointer to the Node we want to add
 *
 * */
void addNode(LinkedList* list, Node* node) {

    if (*list == NULL) {
        *list = node;
    }

    else {
        LinkedList temp = *list;

        while (temp->right != NULL) {
            temp = temp->right; // Here 'right' is working as temp->next
                                // 'left' works as temp->prev
        }

        temp->right = node;
        node->left = temp;
    }
}

/**
 *
 * @author Benjamin Lesieux
 *
 * @brief removes a Node from a Doubly Linked List
 * @param list, a pointer to a pointer of the head of the list (Node** or LinkedList*)
 * @param letter, the ascii value of the letter to delete
 *
 * */
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

/**
 *
 * @author Benjamin Lesieux
 *
 * @brief search for a Node that contains the letter we are searching for
 * @param list, a pointer to the head of the list
 * @param letter, the ascii value of the letter to search
 *
 * @return Node*, a pointer to the node containing the letter
 * */
Node* find(LinkedList list, int letter) {
    if (list != NULL) {
        Node* temp = list;

        while (temp != NULL) {
            if (temp->letter == letter) {
                return temp;
            }

            temp = temp->right;
        }
    }

    else {
        printf("\nCannot search for a letter in an empty list");
    }

    return NULL;
}

/**
 *
 * @author Benjamin Lesieux
 *
 * @brief calculates the size of the linked list
 * @param list, a pointer to the head of the list
 *
 * @return int, the size of the list
 * */
int getSize(LinkedList list) {
    if (list == NULL) {
        return 0;
    }

    else {
        return 1 + getSize(list->right);
    }
}

/**
 *
 * @author Benjamin Lesieux
 *
 * @brief prints the contents of the list
 * @param list, a pointer to the head of the list
 *
 * */
void printList(LinkedList list) {
    if (list != NULL) {
        printf("\nLetter '%c' present %d times ", list->letter, list->occ);
        printList(list->right);
    }
}
