#include <stdio.h>
#include <stdlib.h>
#include "../tests/tests.h"
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
    



    // FileManagement function test (part 1 of project)
    // printf("test FileManagment: %d\n", test_FileManagment());
    // printf("test linked list : %d\n", test_LinkedList());
    // printf("test queue : %d\n", test_Queue());
    // printf("test occ : %d\n", test_Occurrences());
    // printf("test hufftree : %d\n", test_HuffmanTree());

    return EXIT_SUCCESS;
}