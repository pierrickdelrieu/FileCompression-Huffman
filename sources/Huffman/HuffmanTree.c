/**
 * @file HuffmanTree.c
 * @author Harold Molter
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
 * If one of the two nodes is NULL the smaller will be then the existing one
 */
static int compareNodeQueue(Node *node1, Node *node2) {
    if ((node1 == NULL) && (node2 == NULL)) {
        return 0;
    } else if ((node1 == NULL) && (node2 != NULL)) {
        return 1;
    } else if ((node1 != NULL) && (node2 == NULL)) {
        return -1;
    } else if ((node1->data == NULL) && (node2->data == NULL)) {
        return 0;
    } else if ((node1->data == NULL) && (node2->data != NULL)) {
        return -1;
    } else if ((node1->data != NULL) && (node2->data == NULL)) {
        return 1;
    } else if (node1->data->occ > node2->data->occ) {
        return 1;
    } else if (node1->data->occ < node2->data->occ) {
        return -1;
    } else {
        return 0;
    }
}

/**
 * @brief Get the Min object
 * @details The function compare compareNodeQueue is essential for the operation of this function
 * 
 * @param occQueue Queue of occurrence sort
 * @param nodeQueue Tail containing Huffman Nodes
 * @return HuffmanNode* The smaller node of the two queues (by favoring the queue of occurrence if the occurences are equal)
 */
static HuffmanNode* getMin(Queue* occQueue, Queue* nodeQueue) {

    HuffmanNode* min = NULL;

    int compare = compareNodeQueue(occQueue->first, nodeQueue->first);

    if (compare == 1) {
        min = pullQueue(&nodeQueue);
    } else if (compare == -1) {
        min = pullQueue(&occQueue);
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

    return NULL;
}