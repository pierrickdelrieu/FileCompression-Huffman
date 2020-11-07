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


/**
 * @brief FileManagement function test (part 1 of project)
 * 
 * @return int 1 if test ok and 0 else
 */
int test_FileManagment() {

    // Text to be introduced in the file to compress
    char* txt = "Alice was beginning to get very tired of sitting by her sister on the bank, and of having nothing to do";
    int nbCaraFileToCompress = 103;

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

    if((numberCharInFile("TextFiles/FileToCompress.txt") == nbCaraFileToCompress) || (numberCharInFile("TextFiles/BinaryFile.txt") == nbCaraFileToCompress * SIZE_BINARY)) {
        return 1;
    }
    else {
        return 0;
    }
}