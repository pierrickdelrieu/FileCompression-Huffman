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
 * @brief FileManagement function test (part 1 of project)
 * 
 * @return int 1 if test ok and 0 else
 */
int test_FileManagment() {

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

    createBinaryFileOfFileToCompress();

    if((numberCharInFile("TextFiles/FileToCompress.txt") == 103) || (numberCharInFile("TextFiles/BinaryFile.txt") == 824)) {
        return 1;
    }
    else {
        return 0;
    }
}

int test_LinkedList() {
    LinkedList list = createNode((int) 'c', 3);
    Node* b = createNode((int) 'b', 2);
    Node* d = createNode((int) 'd', 1);

    addNode(&list, b); printf("\nAdded 'b' to the list");
    addNode(&list, d); printf("\nAdded 'd' to the list");

    printList(list);

    printf("\nResearching letter 'f'");
    if (find(list, (int) 'f') == NULL) printf("\nLetter 'f' not found as expected");
    else printf("\nThere might be an error :(");

    printf("\nResearching letter 'c'");
    if (find(list, (int) 'c') != NULL) printf("\nLetter 'c' was found as expected");
    else printf("\nThere might be an error :(");

    printf("\nList has 3 elements, getSize returns %d", getSize(list));

    removeNode(&list, (int) 'c');
    removeNode(&list, (int) 'd');
    addNode(&list, createNode((int) 'c', 2));

    printList(list);
    printf("\nList has 2 elements, getSize returns %d", getSize(list));

    return 0;
}

/**
* @brief test function for analysing occurrence of characters in a file occ_char()
* @date 08-11-2020
* @author Harold Molter
*/
int test_occurrence() {
    LinkedList list = occ_char();
    printList(list);
    return 0;
}