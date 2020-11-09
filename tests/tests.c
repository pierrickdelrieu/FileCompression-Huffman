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
    LinkedList list = createNode((int) 'c', 3);
    Node* b = createNode((int) 'b', 2);
    Node* d = createNode((int) 'd', 1);

    addNode(&list, b);
    addNode(&list, d);

    if (find(list, (int) 'f') != NULL) return 0;

    if (find(list, (int) 'c') == NULL) return 0;

    if(getSize(list) != 3) return 0;

    removeNode(&list, (int) 'c');
    removeNode(&list, (int) 'd');
    addNode(&list, createNode((int) 'c', 2));

    if (getSize(list) != 2) return 0;

    return 1;
}