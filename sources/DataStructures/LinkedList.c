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
 * @brief Creates a node for a doubly linked list
 * @param letter An integer corresponding to the ascii value of the letter
 * @param occ The number of occurrences of the letter
 *
 * @return Node* A pointer to a Node
 * */
Node* createNode(int letter, int occ) {

    Node* newNode = NULL;
    newNode = (Node*) malloc(sizeof(Node));

    if (newNode != NULL) {
        newNode->letter = letter;
        newNode->occ = occ;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    else {
        displayErrorMemoryAllocation();
    }

    return newNode;
}

/**
 * @brief Adds a Node to a Doubly Linked List
 * @param list The head of the list (Node*)
 * @param node A pointer to the Node we want to add
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
 * @brief Removes a Node from a Doubly Linked List
 * @param list A pointer to a pointer of the head of the list (Node** or LinkedList*)
 * @param letter The ascii value of the letter to delete
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
 * @brief Search for a Node that contains the letter we are searching for
 * @param list A pointer to the head of the list
 * @param letter The ascii value of the letter to search
 *
 * @return Node* A pointer to the node containing the letter
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
 * @brief Calculates the size of the linked list
 * @param list A pointer to the head of the list
 *
 * @return int The size of the list
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
 * @brief Prints the contents of the list
 * @param list A pointer to the head of the list
 *
 * */
void printList(LinkedList list) {
    if (list != NULL) {
        printf("\nLetter '%c' present %d times ", list->letter, list->occ);
        printList(list->right);
    }
}
