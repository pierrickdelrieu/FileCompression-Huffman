/**
 * @file LinkedList.c
 * @author Benjamin Lesieux
 * @brief All the basic functions of a linked list
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
 * @brief Creates an HuffmanNode
 * @param letter An integer corresponding to the ascii value of the letter
 * @param occ The number of occurrences of the letter
 *
 * @return HuffmanNode* a pointer to an HuffmanNode
 * */
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


/**
 * @brief Creates a node for a doubly linked list
 *
 * @param huffmanNode the data of the Node
 * @return Node* A pointer to a Node
 * */
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

/**
 * @brief Adds a Node to a Doubly Linked List
 * @param list The head of the list (Node*)
 * @param node A pointer to the Node we want to add
 *
 * */
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

/**
 * @brief Removes an HuffmanNode from a Linked List
 * @param list A pointer to a pointer of the head of the list (Node** or LinkedList*)
 * @param huffmanNode The HuffmanNode we want to delete
 *
 * */
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

/**
 * @brief Search for a Node that contains the letter we are searching for
 * @param list A pointer to the head of the list
 * @param letter The ascii value of the letter to search
 *
 * @return Node* A pointer to the node containing the letter
 * */
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

/**
 * @brief Calculates the size of the linked list
 * @param list A pointer to the head of the list
 *
 * @return int The size of the list
 * */
int getSize(LinkedList list) {
    if (list == NULL) {
        return 0;
    } else {
        return 1 + getSize(list->next);
    }
}
/**
* @brief
* @param
* 
* @return 
**/

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