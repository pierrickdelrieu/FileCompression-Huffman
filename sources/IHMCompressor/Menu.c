/**
 * @file Menu.c
 * @author Pierrick Delrieu
 * @brief Function containing all the functionalities of the software and their display
 * @version 0.1
 * @date 17-11-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../include/IHMCompressor/Menu.h"
#include "../../include/FileManagment.h"
#include "../../include/Huffman/Encoding.h"
#include "../../include/Huffman/Decoding.h"
#include "../../include/IHMCompressor/Scan.h"
#include "../../include/IHMCompressor/Show.h"


#define POURCENT 37


/**
 * @brief Display and user choice of software features
 * 
 * @return int User choice
 */
int displayMenu(void) {
    int choice; // 1 - 2 - 3 - 4

    do {
        cleanTerminal();
        printf("************************************************************************\n");
        printf("                           * FILE COMPRESSOR *                          \n");
        printf("                                (Huffman)                               \n\n");
        
        printf("          Choice :\n");
        printf("                1) Add text to FileToCompress\n");
        printf("                2) Compress File\n");
        printf("                3) Decompress File\n");
        printf("                4) Quit\n\n");

        printf("          Enter value (1-4) : ");
        
        scanInteger(&choice);
    } while((choice != 1) && (choice != 2) && (choice != 3) && (choice != 4));

    return choice;
}


/**
 * @brief Functionality: adding a text in the "FileToCompress.txt" file
 * 
 */
void addText(void) {
    cleanTerminal();
    printf("************************************************************************\n");
    printf("                           * FILE COMPRESSOR *                          \n");
    printf("                                (Huffman)                               \n\n");
    printf("          Enter text : ");
    char* txt = NULL;
    scanString(&txt, 300); // 300 characteres maximum
    initFileToCompress(txt);

    cleanTerminal();
    printf("************************************************************************\n");
    printf("                           * FILE COMPRESSOR *                          \n");
    printf("                                (Huffman)                               \n\n");
    printf("          The text has been added\n");
    stopExe(3);
}



/**
 * @brief Functionality: compression of the "FileToCompress.txt" file with data calculation
 * 
 */
void compressFile(void) {
    char choice; // Q for Quit

    float time;
    clock_t t1, t2;
 
    t1 = clock();
 
    // Programme
    Queue* occQueue = createSortOccQueue();
    HuffmanTree tree = createHuffmanTree(occQueue);
    DicoTree dicoTree = createDicoTree(tree);
    encodingFile(dicoTree);
     
    t2 = clock();
    time = (float)(t2-t1)/CLOCKS_PER_SEC;
    createBinaryFileOfFileToCompress();
    initDictionaryPrinting(dicoTree);

    do {
        cleanTerminal();
        printf("************************************************************************\n");
        printf("                           * FILE COMPRESSOR *                          \n");
        printf("                                (Huffman)                               \n\n");
        printf("          The file has been compressed\n");
        printf("                    Number of characters in FileToCompress : %d\n", numberCharInFile("TextFiles/FileToCompress.txt"));
        printf("                    Number of characters in BinaryFile : %d\n", numberCharInFile("TextFiles/BinaryFile.txt"));
        printf("                    Number of characters in HuffmanCompression : %d\n", numberCharInFile("TextFiles/HuffmanCompression.txt"));
        printf("                    Number of characters in Huffman Dictionary : %d\n\n", numberCharInFile("TextFiles/HuffmanDictionary.txt"));
        printf("                    Compression ratio : %.2f %c\n", ratioCompression(), POURCENT);
        printf("                    Compression time : %f secondes\n\n", time);
        printf("          Enter Q to return to the menu : ");

        scanChara(&choice);

    } while(choice != 'Q');
}


/**
 * @brief Functionality: decompression of the file "FileToCompress.txt" with calculation of the decompression time
 * 
 */
void decompressFile(void) {
    char choice; // Q for Quit

    float time;
    clock_t t1, t2;
 
    t1 = clock();
 
    // Programme
    // ajouter la decompression avec le temps de compression
     
    t2 = clock();
    time = (float)(t2-t1)/CLOCKS_PER_SEC;
    printf("temps = %f\n", time);


    do {
        cleanTerminal();
        printf("************************************************************************\n");
        printf("                           * FILE COMPRESSOR *                          \n");
        printf("                                (Huffman)                               \n\n");
        printf("          The file has been decompressed\n");
        printf("          (cf. File 'HuffmanDecompression.txt)'\n\n");
        printf("                    Decompression time : %f secondes\n\n", time);
        printf("          Enter Q to return to the menu : ");

        scanChara(&choice);

    } while(choice != 'Q');
}