/**
 * @file Decoding.c
 * @author Benjamin Lesieux
 * @brief Decoding functions
 * @version 0.1
 * @date 26-11-2020
 *
 * @copyright Copyright (c) 2020
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/IHMCompressor/Show.h"
#include "../../include/Huffman/Decoding.h"
#include "../../include/Huffman/Dictionary.h"


/**
 * @brief decodes the encoded file into HuffmanDecompression.txt
 * @details from the dictionary file, the function will create an huffmantree that will be use to decode the encoded file
 * */
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

        if (current == NULL) { // Sometimes the tree can be NULL, even if we came from a parent, so we reset it
            current = huffmanTree;
        } else if (current->letter != -1) { // it means we found a leaf ex : (a | 11)
            fputc((char) current->letter, decoding);
            current = huffmanTree; // we start from the beginning, again
        }

        char_f = fgetc(file);
    }

    fclose(decoding);
    fclose(file);
}

/**
 * @brief builds an huffman tree from the dictionary file
 * @param file is the file in which the dictionary is in
 * */
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
        if (char_f != '/' && char_f != '1' && char_f != '0') {
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
        }

        char_f = fgetc(file);
    }

    free(currentCode);

    return tree;
}

/**
 * @brief search and returns the size of the biggest code
 * @param file is the file where the dictionary is
 * @return an unsigned integer that is equal to the size of the biggest code
 * */
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

/**
 * @brief add a node to tree at the place showed by the code
 * @param tree the parent of the huffman tree
 * @param letter the current letter we want to place in the tree
 * @param code the code of the current letter
 * @param index the current index of the code of the letter we are placing
 * @param sizeCode the size of the code
 * */
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

