#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include <unistd.h>
#include "../../include/IHMCompressor/Menu.h"
#include "../../include/FileManagment.h"
#include "../../include/IHMCompressor/Scan.h"
#include "../../include/IHMCompressor/Show.h"


#define POURCENT 37


int displayMenu(void) {
    int choice;
    do {
        cleanTerminal();
        printf("************************************************************************\n");
        printf("                           * FILE COMPRESSOR *                          \n");
        printf("                                (Huffman)                               \n\n");
        
        printf("          Choice :\n");
        printf("                1) Add text to FileTo Compress\n");
        printf("                2) Compress File\n");
        printf("                3) Decompress File\n");
        printf("                4) Quit\n\n");

        printf("          Enter value (1-4) : ");
        
        scanInteger(&choice);
    } while((choice != 1) && (choice != 2) && (choice != 3) && (choice != 4));

    return choice;
}


void addText(void) {
    cleanTerminal();
    printf("************************************************************************\n");
    printf("                           * FILE COMPRESSOR *                          \n");
    printf("                                (Huffman)                               \n\n");
    printf("          Enter text : ");
    char* txt = NULL;
    scanStrings(&txt);
    initFileToCompress(txt);
    cleanTerminal();
    

    printf("************************************************************************\n");
    printf("                           * FILE COMPRESSOR *                          \n");
    printf("                                (Huffman)                               \n\n");
    printf("          The text has been added\n");
    stopExe(3);
    cleanTerminal();
}


void compressFile(void) {
    char choice;

    // ajouter la compression avec le temps de compression


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
        printf("                    Compression time : \n\n");
        printf("          Enter Q to return to the menu : ");

        scanString(&choice);

        cleanTerminal();
    } while(choice != 'Q');
}