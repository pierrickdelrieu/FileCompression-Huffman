#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/IHMCompressor/Show.h"
#include "../../include/Huffman/Decoding.h"
#include "../../include/Huffman/Dictionary.h"
#include "../../include/Huffman/HuffmanTree.h"




void decodeFile() {

    FILE* dico = fopen("TextFiles/HuffmanDictionary.txt", "r");
    HuffmanTree huffmanTree = buildFromDictionary(dico); // We recreate the HuffmanTree from the dictionary
    fclose(dico);

    // We need to open the files so that we can both search in one file and write in the other file
    FILE* file = fopen("TextFiles/HuffmanCompression.txt", "r");
    FILE* decoding = fopen("TextFiles/HuffmanDecompression.txt", "w+");

    if (file == NULL || decoding == NULL) {
        displayErrorMessageOpenFile();
    }

    int char_f = fgetc(file);
    HuffmanTree current = huffmanTree;

    while (char_f != EOF) {

        // We are going through the tree until we find a leaf node containing a letter
        if (char_f == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        if (current->letter != -1) { // it means we found a leaf ex : (a | 11)
            fputc((char) current->letter, decoding);
            current = huffmanTree; // we start from the beginning, again
        }

        char_f = fgetc(file);
    }

    fclose(decoding);
    fclose(file);
    freeHuffmanTree(huffmanTree);
}


HuffmanTree buildFromDictionary(FILE* file) {
    HuffmanTree tree = createHuffmanNode(-1, 0); // creating the parent node

    int currentLetter = 0;
    int sizeCodeMax = getCodeSizeMax(file);
    char* currentCode = (char*) malloc((sizeCodeMax) * sizeof(char));
    int sizeCurrentCode = 0;
    int buildingCode = 0;

    fseek(file, 0, SEEK_SET); // we set the pointer at the beginning of the file so that we don't miss anything

    int char_f = fgetc(file);

    while (char_f != EOF) {
        currentLetter = char_f; // it means we found a letter
        buildingCode = 1;

        while (buildingCode == 1) {
            char_f = fgetc(file); // going to next character until we complete the code

            currentCode[sizeCurrentCode] = (char) char_f;
            sizeCurrentCode++;

            if (char_f == '/') {
                currentCode[sizeCurrentCode-1] = '\0'; // it means we reached the end of the code
                buildingCode = 0;
            }
        }

        buildFromCode(tree, currentLetter, currentCode, 0, sizeCurrentCode-1); // we build the child node at the place the code would be
        sizeCurrentCode = 0;
        

        char_f = fgetc(file);
    }

    free(currentCode);

    return tree;
}


unsigned int getCodeSizeMax(FILE* file) { // the code is almost the same as the function above
    unsigned int sizeCode = 0;
    unsigned int max = 0;
    int buildingCode = 0;
    int char_f = fgetc(file);

    while (char_f != EOF) {
        if (char_f != '/' && char_f != '1' && char_f != '0') {
            buildingCode = 1;

            while (buildingCode == 1) {
                char_f = fgetc(file);

                sizeCode++;

                if (char_f == '/') {
                    buildingCode = 0;

                    if (max < sizeCode) {
                        max = sizeCode;
                    }
                }
            }

            sizeCode = 0;
        }

        char_f = fgetc(file);
    }

    return max;
}


void buildFromCode(HuffmanTree tree, char letter, char* code, int index, int sizeCode) {
    if (tree != NULL && index != sizeCode) {
        if (code[index] == '1') {
            if (tree->right == NULL) {
                if (index == sizeCode-1) {
                    tree->right = createHuffmanNode((int) letter, 0); // We build the leaf
                } else {
                    tree->right = createHuffmanNode(-1, 0); // We build a parent

                }
            }

            buildFromCode(tree->right, letter, code, index + 1, sizeCode); // We continue to travel
        } else {
            if (tree->left == NULL) {
                if (index == sizeCode-1) {
                    tree->left = createHuffmanNode((int) letter, 0); // We build a leaf
                } else {
                    tree->left = createHuffmanNode(-1, 0); // We build a parent
                }
            }

            buildFromCode(tree->left, letter, code, index + 1, sizeCode); // We continue to travel
        }
    }
}

