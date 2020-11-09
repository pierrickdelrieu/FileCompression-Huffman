#include <stdio.h>
#include <stdlib.h>
#include "../include/FileManagment.h"
#include "../include/Huffman/Encoding.h"
#include "../include/Huffman/Decoding.h"
#include "../tests/tests.h"




int main(void) {

    // FileManagement function test (part 1 of project)
    printf("test FileManagment: %d\n", test_FileManagment());
    printf("test linked list : %d\n", test_LinkedList());
    printf("test queue : %d\n", test_Queue());

    return EXIT_SUCCESS;
}