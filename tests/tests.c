/**
 * @file tests.c
 * @author Pierrick Delrieu - Benjamin Lesieux - Harold Molter
 * @brief function test of project
 * @version 0.3
 * @date 07-11-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "../include/FileManagment.h"
#include "../include/DataStructures/LinkedList.h"
#include "../include/DataStructures/Queue.h"
#include "../include/Huffman/HuffmanTree.h"


/**
 * @brief Initialization of the contents of the file to compress in order to know the noramlement results obtained
 * 
 */
static void initFileToCompress(char *txt) {
    FILE *file = NULL;
    file = fopen("TextFiles/FileToCompress.txt", "w");

    // If the file is opened correctly
    if (file != NULL) {
        fputs(txt, file);
        fclose(file);
    }
        // If the file is not opened correctly
    else {
        printf("TEST : FILE OPENING ERROR\n");
        exit(EXIT_FAILURE); // Forced program exit with failure
    }
}


/**
 * @brief FileManagement function test (part 1 of project)
 * 
 * @return int 1 if test ok and 0 else
 */
int test_FileManagment(void) {
    int nbCaraFileToCompress = 103;

    initFileToCompress(
            "Alice was beginning to get very tired of sitting by her sister on the bank, and of having nothing to do");

    createBinaryFileOfFileToCompress();

    if ((numberCharInFile("TextFiles/FileToCompress.txt") == nbCaraFileToCompress) ||
        (numberCharInFile("TextFiles/BinaryFile.txt") == nbCaraFileToCompress * SIZE_BINARY)) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * @brief LinkedList function test (part 2 of project)
 *
 * @return int 1 if test ok and 0 else
 */
int test_LinkedList(void) {
    LinkedList head = createNode(createHuffmanNode((int) 'b', 4));
    addNode(&head, createNode(createHuffmanNode((int) 'e', 2)));
    addNode(&head, createNode(createHuffmanNode((int) 'n', 8)));


    // size is supposed to be 3
    if (getSize(head) != 3) return 0;

    // we are supposed to find 'b'
    if (find(head, 'b') == NULL) return 0;

    // we are not supposed to find 'h'
    if (find(head, 'h') != NULL) return 0;

    removeNode(&head, head->data);
    removeNode(&head, head->next->data);

    addNode(&head, createNode(createHuffmanNode((int) 'o', 2)));

    // size is supposed to be 2
    if (getSize(head) != 2) return 0;

    return 1;
}

static void displayQueue(Queue *queue) {
    Node *head = queue->last;
    while (head != NULL) {
        printf("(%c | %d) -> ", head->data->letter, head->data->occ);
        head = head->next;
    }
}

/**
 * @brief Queue function test (part 2 of project)
 * @details Test with queue NULL and not NULL
 *
 * @return int 1 if test ok and 0 else
 */
int test_Queue(void) {
    // Init queue
    Queue *queue = initQueue();

    LinkedList head = createNode(createHuffmanNode((int) 'b', 8));
    addNode(&head, createNode(createHuffmanNode((int) 'e', 4)));
    addNode(&head, createNode(createHuffmanNode((int) 'n', 2)));

    queue->last = head;
    queue->first = head->next->next;
    if (getSize(queue->last) != 3) return 0;

    // Display queue
    //displayQueue(queue);
    //printf("\n");

    // PushQueue
    HuffmanNode *x = createHuffmanNode((int) 'z', 24);
    pushQueue(&queue, x);
    if (getSize(queue->last) != 4) return 0;
    // Display queue
    //displayQueue(queue);


    // PullQueue
    x = pullQueue(&queue);
    if (getSize(queue->last) != 3) return 0;
    //printf("\n noued retiré : ");
    //printf("(%c | %d) \n", x->letter, x->occ);
    // Display queue
    //displayQueue(queue);
    //printf("\n");

    return 1;

}


static void displayLinkedList(LinkedList l) {
    Node *head = l;
    while (head != NULL) {
        printf("(%c | %d) -> ", head->data->letter, head->data->occ);
        head = head->next;
    }
}

/**
* @brief Test function for analysing occurrence of characters in a file occChar()
 * @return int 1 if test ok and 0 else
*/
int test_Occurrences(void) {
    initFileToCompress("");
    LinkedList list = occChar();
    if ((list == NULL) && (numberCharInFile("TextFiles/FileToCompress.txt") != 0)) return 0;
    if ((list != NULL) && (numberCharInFile("TextFiles/FileToCompress.txt") == 0)) return 0;
    if (getSize(list) != numberCharInFile("TextFiles/FileToCompress.txt")) return 0;
    // displayLinkedList(list);
    return 1;
}

static void displayTree(HuffmanTree tree) {
    if (tree != NULL) {
        printf("\n (%d | %d) ", tree->letter, tree->occ);
        displayTree(tree->left);
        displayTree(tree->right);
    }
}

/**
 * @brief Creating a Huffman tree with the two-queue process
 * @details Verification of the tree obtained using: https://csfieldguide.org.nz/en/interactives/huffman-tree/
 * 
 * @return int Returns 1 all the time if there is no error during execution
 */
int test_HuffmanTree(void) {
    LinkedList head = createNode(createHuffmanNode((int) 'a', 5));
    addNode(&head, createNode(createHuffmanNode((int) 'z', 5)));
    addNode(&head, createNode(createHuffmanNode((int) 's', 5)));
    addNode(&head, createNode(createHuffmanNode((int) 'e', 4)));
    addNode(&head, createNode(createHuffmanNode((int) 'd', 3)));
    addNode(&head, createNode(createHuffmanNode((int) 'r', 3)));
    addNode(&head, createNode(createHuffmanNode((int) 'v', 3)));
    addNode(&head, createNode(createHuffmanNode((int) 'c', 1)));
    addNode(&head, createNode(createHuffmanNode((int) 'd', 1)));
    addNode(&head, createNode(createHuffmanNode((int) 'm', 1)));


    Queue* occQueue = initQueue(); // Queue is sorted
    occQueue->last = head;
    occQueue->first = head->next->next->next->next->next->next->next->next->next;
    //printf("\nWe have the following Queue : ");
    // displayQueue(occQueue);

    HuffmanTree tree = createHuffmanTree(occQueue);
    // displayTree(tree);

    return 1;
}
