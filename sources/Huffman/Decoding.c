#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/IHMCompressor/Show.h"
#include "../../include/Huffman/Decoding.h"
#include "../../include/Huffman/Dictionary.h"

char* buildString(FILE *file) {



    return NULL;
}

char* decodeFile(FILE *file) {

    int char_f = fgetc(file);
    HuffmanTree huffmanTree = buildFromDictionary(file); // We recreate the HuffmanTree from the dictionary
    HuffmanTree current = huffmanTree;
    int numLetters = getSizeFile(file);

    int count = 0;

    char* decoded = (char*) malloc(numLetters * sizeof(char));

    while (char_f != EOF) {
            if (char_f == '0') {
                current = current->left;
            } else {
                current = current->right;
            }

            if (current->letter != -1) { // it means we found a leaf ex : (a | 11)
                decoded[count] = (char) current->letter;
                current = huffmanTree; // we start from the beginning, again
            }

        char_f = fgetc(file);
        count++;
    }

    fclose(file);
    return decoded;
}

HuffmanTree buildFromDictionary(FILE* file) {
    HuffmanTree tree = createHuffmanNode(-1, 0);

    int currentLetter = 0;
    int sizeCodeMax = getCodeSizeMax(file);
    printf("%d\n", sizeCodeMax);
    char* currentCode = (char*) malloc(sizeCodeMax * sizeof(char));
    int sizeCurrentCode = 0;
    int buildingCode = 0;

    fseek(file, 0, SEEK_SET);

    int char_f = fgetc(file);

    while (char_f != EOF) {
        if (char_f != '/' && char_f != '1' && char_f != '0') {
            currentLetter = char_f;
            buildingCode = 1;

            while (buildingCode == 1) {
                char_f = fgetc(file);

                currentCode[sizeCurrentCode] = (char) char_f;
                sizeCurrentCode++;

                if (char_f == '/') {
                    currentCode[sizeCurrentCode-1] = '\0';
                    buildingCode = 0;
                }
            }

            buildFromCode(tree, currentLetter, currentCode, 0, sizeCurrentCode-1);
            sizeCurrentCode = 0;
            free(currentCode);
            currentCode = (char*) malloc(sizeCodeMax * sizeof(char));
        }

        char_f = fgetc(file);
    }

    return tree;
}


unsigned int getCodeSizeMax(FILE* file) {
    int sizeCode = 0;
    int max = 0;
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

unsigned int getSizeFile(FILE* file) {
    int sizeFile = 0;
    int char_f = fgetc(file);

    while (char_f != EOF) {
        sizeFile++;
        char_f = fgetc(file);
    }

    return sizeFile;
}

void buildFromCode(HuffmanTree tree, char letter, char* code, int index, int sizeCode) {
    if (tree != NULL && index != sizeCode) {
        if (code[index] == '1') {
            if (tree->right == NULL) {
                if (index == sizeCode-1) {
                    tree->right = createHuffmanNode((int) letter, 0);
                } else {
                    tree->right = createHuffmanNode(-1, 0);

                }
            }

            buildFromCode(tree->right, letter, code, index + 1, sizeCode);
        } else {
            if (tree->left == NULL) {
                if (index == sizeCode-1) {
                    tree->left = createHuffmanNode((int) letter, 0);
                } else {
                    tree->left = createHuffmanNode(-1, 0);
                }
            }

            buildFromCode(tree->left, letter, code, index + 1, sizeCode);
        }
    }
}

//Queue* occListFromFile(FILE* file) {
//    LinkedList list = NULL;
//    Queue* queue = initQueue();
//    int char_f = fgetc(file);
//
//    while (char_f != EOF) {
//
//        //printf("%d\n", char_f);
//
//        if (char_f != '/' && char_f != '0' && char_f != '1') { // means we found a letter
//            if (list == NULL) {
//                list = createNode(createHuffmanNode(char_f, 0));
//                pushQueue(&queue, list->data);
//            } else {
//                LinkedList new = createNode(createHuffmanNode(char_f, 0));
//                addNode(list, new);
//                pushQueue(&queue, new->data);
//            }
//        }
//
//        char_f = fgetc(file);
//    }
//
//
//    // Queue was made in decreasing order, we reverse it to have it in an increasing order
//    reverseQueue(&queue);
//
//    return queue;
//}