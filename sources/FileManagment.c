/**
 * @file FileManagment.c
 * @author Pierrick Delrieu
 * @brief Converting a Text File to Binary Text and Counting Items in a File
 * @details Part 1 of project
 * @version 0.1
 * @date 01-11-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/FileManagment.h"
#include "../include/IHMCompressor/Show.h"


/**
 * @brief Memory allocation of the Binary structure and of the 1D array representing the bytes
 * 
 * @param size Array size, number of bits used to represent the number
 * @return Binary* Pointer to allocated structure
 */
Binary* createBinaryNumber(int size) {
    Binary* x = NULL;

    x = (Binary*) malloc(sizeof(Binary));

    // Allocation of an array of 8 integers
    x->nb = (int*) malloc(size * sizeof(int));

    // Reset boxes to char(0) = int(48)
    int i;
    for(i = 0; i < size; i++) {
        x->nb[i] = ASCII_INIT_NUMBER;
    }

    return x;
}



/**
 * @brief Converting integer to binary number (0 and 1)
 * @details In the table the 0 and 1 are represented in decimal form either according to the ascii table 
 * charactere(0) -> decimal(48) and charactere(1) -> decimal(49)
 * 
 * @param value Integer to convert
 * @return Binary* 1D array of size 8. Each box represents one byte.
 */
Binary* convertIntToBinary(int value) {
    Binary* x = createBinaryNumber(SIZE_BINARY);

    int i = SIZE_BINARY-1; // Size of array binary number

    // Conversion with the Euclidean division method
    while(value > 0) {
        x->nb[i] = (value%2) + ASCII_INIT_NUMBER;
        value = value/2;
        i--;
    }

    return x;
}



/**
 * @brief Creation of a binary number file 'BinaryFile.txt' containing the equivalent of the character file 'FileToCompress'
 * @details 'fileToCompress' is open in read-only mode because we don't need to modify it
 * 'binaryFile' is open read and write
 * 
 */
void createBinaryFileOfFileToCompress(void) {
    FILE* fileToCompress = NULL;
    FILE* binaryFile = NULL;

    fileToCompress = fopen("TextFiles/FileToCompress.txt","r"); // Open read-only
    binaryFile = fopen("TextFiles/BinaryFile.txt","w"); // Open read and write

    // If the files are opened correctly
    if((fileToCompress != NULL) && (binaryFile != NULL)) {
        int chara = fgetc(fileToCompress); // Contains the item currently playing
        int i; // Counter
        Binary* bin = NULL; // Array containing the content of the variable chara in binary form (0 and 1)

        // While the cursor is not at the end of the file
        while(chara != EOF) {
            bin = convertIntToBinary(chara);
            for(i=0; i<SIZE_BINARY; i++) {
                fputc(bin->nb[i], binaryFile);
            }

            chara = fgetc(fileToCompress);
        }

        fclose(fileToCompress);
        fclose(binaryFile);
    }
    // If the files are not opened correctly
    else {
        displayErrorMessageOpenFile();
    }
}



/**
 * @brief Counting the number of characters in a file
 * 
 * @param filePath Character string containing the path (from the main folder) to the file to be processed
 * @return int Number of characters in the file
 */
int numberCharInFile(char* filePath) {
    FILE* file = NULL;

    file = fopen(filePath,"r"); // Open read-only
    
    // If the file is opened correctly
    if(file != NULL) {
        int nbChara = 0; // Initialization of the number of characters

        // While the cursor is not at the end of the file
        while(fgetc(file) != EOF) {
            nbChara = nbChara + 1;
        }

        fclose(file);

        return nbChara;
    }
    // If the file is not opened correctly
    else {
        displayErrorMessageOpenFile();
    }

    return 0;
}
