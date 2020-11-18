#include <stdio.h>
#include <stdlib.h>
#include "../include/FileManagment.h"
#include "../include/Huffman/Encoding.h"
#include "../include/Huffman/Decoding.h"
#include "../tests/tests.h"
//for commit
int main(void) {

    // FileManagement function test (part 1 of project)
    printf("test FileManagment: %d\n", test_FileManagment());
    printf("test linked list : %d\n", test_LinkedList());
    printf("test queue : %d\n", test_Queue());
    printf("test occ : %d\n", test_Occurrences());
    printf("test hufftree : %d\n", test_HuffmanTree());
    printf("Test dictionary : %d\n", test_Dictionary());


    return EXIT_SUCCESS;
}