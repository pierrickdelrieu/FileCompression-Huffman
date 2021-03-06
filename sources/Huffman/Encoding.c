

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/IHMCompressor/Show.h"
#include "../../include/Huffman/Encoding.h"



void encodingFile(DicoTree tree) {
    FILE* fileToCompress = NULL;
    FILE* huffmanCompression = NULL;


    fileToCompress = fopen("TextFiles/FileToCompress.txt", "r");
    huffmanCompression = fopen("TextFiles/HuffmanCompression.txt", "w");

    if((fileToCompress!=NULL) && (huffmanCompression!=NULL)) {
        char letter;
        char* code = NULL;
        letter = fgetc(fileToCompress);

        while (letter!=EOF) {
            code = getCodeLetter(tree, letter);
            
            if(code != NULL) {
                fputs(code, huffmanCompression);
            }
            letter = fgetc(fileToCompress);
        }

        fclose(fileToCompress);
        fclose(huffmanCompression);
    }
    else {
        displayErrorMessageOpenFile();
    }
}






char* getCodeLetter(DicoTree tree, char letter) {
    if (tree != NULL) {
        if (tree->letter == letter) {
            return tree->code;
        } else if (tree->letter > letter) {
            return getCodeLetter(tree->left, letter);
        } else {
            return getCodeLetter(tree->right, letter);
        }
    }
}