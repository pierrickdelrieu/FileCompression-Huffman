/**
 * @file tests.c
 * @author Pierrick Delrieu
 * @brief function test of project
 * @version 0.1
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


/**
 * @brief Initialization of the contents of the file to compress in order to know the noramlement results obtained
 * 
 */
static void initFileToCompress(void) {
    // Text to be introduced in the file to compress
    char* txt = "Alice was beginning to get very tired of sitting by her sister on the bank, and of having nothing to do";

    FILE* file = NULL;
    file = fopen("TextFiles/FileToCompress.txt","w");
    
    // If the file is opened correctly
    if(file != NULL) {
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
int test_FileManagment() {
    int nbCaraFileToCompress = 103;

    initFileToCompress();

    createBinaryFileOfFileToCompress();

    if((numberCharInFile("TextFiles/FileToCompress.txt") == nbCaraFileToCompress) || (numberCharInFile("TextFiles/BinaryFile.txt") == nbCaraFileToCompress * SIZE_BINARY)) {
        return 1;
    }
    else {
        return 0;
    }
}

/**
 * @brief LinkedList function test (part 2 of project)
 *
 * @return int 1 if test ok and 0 else
 */
int test_LinkedList() {

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