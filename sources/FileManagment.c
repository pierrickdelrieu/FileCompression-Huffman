#include <stdio.h>
#include <stdlib.h>
#include "../include/FileManagment.h"
#include "../include/IHMCompressor/Show.h"



void initFileToCompress(char *txt) {
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



Binary *createBinaryNumber(int size) {
    Binary *x = NULL;

    x = (Binary *) malloc(sizeof(Binary));

    // Allocation of an array of 8 integers
    x->nb = (int *) malloc(size * sizeof(int));

    // Reset boxes to char(0) = int(48)
    int i;
    for (i = 0; i < size; i++) {
        x->nb[i] = ASCII_INIT_NUMBER;
    }

    return x;
}



Binary *convertIntToBinary(int value) {
    Binary *x = createBinaryNumber(SIZE_BINARY);

    int i = SIZE_BINARY - 1; // Size of array binary number

    // Conversion with the Euclidean division method
    while (value > 0) {
        x->nb[i] = (value % 2) + ASCII_INIT_NUMBER;
        value = value / 2;
        i--;
    }

    return x;
}



void createBinaryFileOfFileToCompress(void) {
    FILE *fileToCompress = NULL;
    FILE *binaryFile = NULL;

    fileToCompress = fopen("TextFiles/FileToCompress.txt", "r"); // Open read-only
    binaryFile = fopen("TextFiles/BinaryFile.txt", "w"); // Open read and write

    // If the files are opened correctly
    if ((fileToCompress != NULL) && (binaryFile != NULL)) {
        int chara = fgetc(fileToCompress); // Contains the item currently playing
        int i; // Counter
        Binary *bin = NULL; // Array containing the content of the variable chara in binary form (0 and 1)

        // While the cursor is not at the end of the file
        while (chara != EOF) {
            bin = convertIntToBinary(chara);
            for (i = 0; i < SIZE_BINARY; i++) {
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



int numberCharInFile(char *filePath) {
    FILE *file = NULL;

    file = fopen(filePath, "r"); // Open read-only

    // If the file is opened correctly
    if (file != NULL) {
        int nbChara = 0; // Initialization of the number of characters

        // While the cursor is not at the end of the file
        while (fgetc(file) != EOF) {
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



float ratioCompression(void) {
    float nbHuffmanCompression = (float) (numberCharInFile("TextFiles/HuffmanCompression.txt") + numberCharInFile("TextFiles/HuffmanDictionary.txt"));
    float nbBinaryFile = (float) numberCharInFile("TextFiles/BinaryFile.txt");

    if((nbBinaryFile == 0) || (nbHuffmanCompression == 0)){
        return 0;
    }
    else {
        return (nbHuffmanCompression/nbBinaryFile) * 100;
    }
}
