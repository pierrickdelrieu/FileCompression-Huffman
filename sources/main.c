#include <stdio.h>
#include <stdlib.h>
#include "../include/IHMCompressor/Menu.h"

#define ADDTEXT 1
#define COMPRESS 2
#define DECOMPRESS 3
#define QUIT 4

int main(void) {
    int choice = QUIT;
    do {
        choice = displayMenu();

        if(choice == ADDTEXT) {
            addText();
        } 
        else if(choice == COMPRESS) {
            compressFile();
        }
        else if(choice == DECOMPRESS) {
            decompressFile();
        }
    } while(choice != QUIT);
    

    return EXIT_SUCCESS;
}