/**
 * @file HuffmanTree.c
 * @author Pierrick Delrieu - Benjamins Lesieux - Harold Molter
 * @brief 
 * @version 0.1
 * @date 08-11-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include "../../include/Huffman/HuffmanTree.h"
#include "../../include/IHMCompressor/Show.h"


/**
* @brief function to determine the number of occurence of a character in a file
* 
* @return list of char with their respective occurrence
*/
LinkedList occChar(void) {

    FILE *file = NULL;
    file = fopen("TextFiles/FileToCompress.txt", "r");    // access path to verify...?

    // checking if file is open
    if (file != NULL) {
        LinkedList list = NULL;                                // list to return
        LinkedList temp = NULL;                                // copy of list, to go through it
        int char_f = fgetc(file);                            // char being read in file

        list = createNode(createHuffmanNode(char_f, 1));

        // go through whole file
        while (char_f != EOF) {
            char_f = fgetc(file);
            temp = find(list, char_f);                        // check if char already in list

            // letter is in list
            if (temp != NULL) {
                temp->data->occ = temp->data->occ + 1;
            }
                // letter not in list
            else {
                LinkedList newE = createNode(createHuffmanNode(char_f, 1));
                addNode(&list, newE);
            }
        }
        fclose(file);

        // Remove char(EOF)
        HuffmanNode *eof = find(list, EOF)->data;
        removeNode(&list, eof);


        return list;
    } else {
        displayErrorMessageOpenFile();
    }

    return NULL;
}

/**
 * @brief Compare huffman nodes according to their occurrence
 * 
 * @param node1 Node to compare
 * @param node2 Node to compare
 * @return int 1 if occ(node1) > occ(node2)
 *             -1 if occ(node1) < occ(node2)
 *             0 if occ(node1) = occ(node2)
 */
int compareHuffmanNode(HuffmanNode *node1, HuffmanNode *node2) {
    if ((node1 == NULL) && (node2 == NULL)) {
        return 0;
    } else if ((node1 == NULL) && (node2 != NULL)) {
        return -1;
    } else if ((node1 != NULL) && (node2 == NULL)) {
        return 1;
    } else if (node1->occ > node2->occ) {
        return 1;
    } else if (node1->occ < node2->occ) {
        return -1;
    } else {
        return 0;
    }
}

// HuffmanNode* returnSortNode(Queue* occQueue; Queue* nodeQueue)

HuffmanNode* getMin(Queue* occQueue, Queue* nodeQueue) {

    HuffmanNode* min = NULL;

    int compare = compareHuffmanNode(occQueue->first, nodeQueue->first);

    if (compare == 1) {
        min = pullQueue(&occQueue);
    } else if (compare == -1) {
        min = pullQueue(&nodeQueue);
    } else {
        min = pullQueue(&occQueue);
    }

    return min;
}

HuffmanTree createHuffmanTree(Queue* occQueue) {

    Queue *nodeQueue = initQueue();

    if (getSize(occQueue->last) <= 1) { // Si la file initiale n'a qu'un HuffmanNode => rien à construire.
        return pullQueue(&occQueue);    // returns NULL if empty, the only node if not
    }

    while ((getSize(occQueue->last) != 0) || (getSize(nodeQueue->last) >= 1)) {

//        printf("\nOccQueue : ");
//        displayQueue(occQueue);
//        printf("\nNodeQueue : ");
//        displayQueue(nodeQueue);

        int occQSize = getSize(occQueue->last);
        int nodeQSize = getSize(nodeQueue->last);

        if ((occQSize + nodeQSize) < 2)  { // occQSize forcément nul et nodeQSize forcément égal à 1
            return pullQueue(&nodeQueue);  // On retourne donc directement le parent final
        } else {
            HuffmanNode* min1 = getMin(occQueue, nodeQueue);
            HuffmanNode* min2 = getMin(occQueue, nodeQueue);

            HuffmanTree parent = createHuffmanNode(-1, min1->occ + min2->occ);
            parent->right = min1;
            parent->left = min2;

            pushQueue(&nodeQueue, parent);
        }
    }
}




/**
 * @brief Create a Sort Queue From Occ List object
 * 
 * @param list 
 * @return Queue* 
 */
Queue* createSortOccQueue(void) { 

    Node* list = occChar();
    
    // list not empty
    if (list != NULL) {
        int nb = 1;                     // security on pushQueue
        Node* min = NULL;               // Node with least occurrences
        Node* prec = NULL;              // Previous Node of min
        Queue* f = initQueue();         // Queue to return

        // Repeat process size times to go through whole list
        while((list != NULL) && (nb != 0)) {

            // prec always initialised to first node and min is being searched
            prec = list;
            min = findMinOccLetter(list);

            // Node with least occurrences is the first one
            if (prec == min) {
                list = list->next;
                nb = pushQueue(&f, min->data);
            }
            // go through list to find previous Node of min
            else {
                while (prec->next != min) {
                    prec = prec->next;
                }

                // connect previous Node to the one after min and enqueue min
                prec->next = min->next;
                nb = pushQueue(&f, min->data); // don't know how to use it though
            }
        }
        return f;

        // list is empty
    }

    // list is empty
    return NULL;
    
}