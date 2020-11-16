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
    int choice = scanChoiceMenu();
    cleanTerminal();


    return choice;
}


void addText(void) {
    printf("************************************************************************\n");
    printf("                             FILE COMPRESSOR                            \n");
    printf("                                (Huffman)                               \n\n");
    printf("          Enter text : ");
    char* txt = scanText();
    initFileToCompress(txt);
    cleanTerminal();
    sleep(3);
    

    printf("************************************************************************\n");
    printf("                             FILE COMPRESSOR                            \n");
    printf("                                (Huffman)                               \n\n");
    printf("          The text has been added\n");
    cleanTerminal();
}