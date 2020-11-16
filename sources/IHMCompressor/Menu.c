#include <stdio.h>
#include <stdlib.h>
#include "../../include/IHMCompressor/Menu.h"
#include "../../include/FileManagment.h"
#include "../../include/IHMCompressor/Scan.h"
#include "../../include/IHMCompressor/Show.h"


#define ADDTEXT 1
#define COMPRESS 2
#define DECOMPRESS 3
#define QUIT 4
#define POURCENT 37


int displayMenu(void) {

    printf("************************************************************************\n");
    printf("                             FILE COMPRESSOR                            \n");
    printf("                                (Huffman)                               \n\n");
    
    printf("          Choice :\n");
    printf("                1) Add text to FileTo Compress\n");
    printf("                2) Compress File\n");
    printf("                3) Decompress File\n");
    printf("                4) Quit\n\n");

    printf("          Enter value (1-4) : ");
    // int choice = scanChoiceMenu();
    cleanTerminal();


    return 1;
}


void addText(void) {
    printf("************************************************************************\n");
    printf("                           * FILE COMPRESSOR *                          \n");
    printf("                                (Huffman)                               \n\n");
    printf("          Enter text : ");
    // char* txt = scanText();
    // initFileToCompress(txt);
    cleanTerminal();
    

    printf("************************************************************************\n");
    printf("                           * FILE COMPRESSOR *                          \n");
    printf("                                (Huffman)                               \n\n");
    printf("          The text has been added\n");
    // sleep(3);
    cleanTerminal();
}


void compressFile(void) {
    char choice;

    // ajouter la compression avec le temps de compression

    do {
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
        
        scanf("%c",&choice);

        cleanTerminal();
    } while(choice != 'Q');
}