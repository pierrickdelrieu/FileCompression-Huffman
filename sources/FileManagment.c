#include <stdio.h>
#include <stdlib.h>
#include "../include/FileManagment.h"
#include "../include/IHMCompressor/Show.h"





Binary* create_binary_number() {
    Binary* x = NULL;

    x = (Binary*) malloc(sizeof(Binary));
    x->nb = (int*) calloc(SIZE_BINARY, sizeof(int));

    return x;
}


Binary* convert_int_to_binary(int value) {
    Binary* x = create_binary_number();

    int i = SIZE_BINARY-1; // size of array binary number

    // conversion avec la méthode de la division
    while(i >= 0) {
        x->nb[i] = (value%2) + ASCII_INIT_NUMBER;
        value = value/2;
        i--;
    }

    return x;
}



void create_binary_file_of_FileToCompress() {
    FILE* fileToCompress = NULL;
    FILE* binaryFile = NULL;

    fileToCompress = fopen("TextFiles/FileToCompress.txt","r"); // Open read-only
    binaryFile = fopen("TextFiles/BinaryFile.txt","w"); // Open read and write

    // If the file is opened correctly
    if((fileToCompress != NULL) && (binaryFile != NULL)) {
        int chara = fgetc(fileToCompress);
        int i;
        Binary* bin = NULL;


        while(chara != EOF) {
            bin = convert_int_to_binary(chara);
            for(i=0; i<SIZE_BINARY; i++) {
                fputc(bin->nb[i], binaryFile);
            }

            chara = fgetc(fileToCompress);
        }

        fclose(fileToCompress);
        fclose(binaryFile);
    }
    // If the file is not opened correctly
    else {
        displayErrorMessageOpenFile();
    }


}



int number_char_in_file(char* filePath) {
    FILE* file = NULL;

    file = fopen(filePath,"r"); // Open read-only

    // If the file is opened correctly
    if(file != NULL) {
        int nbChara = 0;
        char cara = fgetc(file);

        while(cara != EOF) {
            nbChara = nbChara + 1;
            cara = fgetc(file);
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
