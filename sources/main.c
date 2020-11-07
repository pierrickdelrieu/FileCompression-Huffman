#include <stdio.h>
#include <stdlib.h>
#include "../include/FileManagment.h"
#include "../include//Huffman/Encoding.h"
#include "../include//Huffman/Decoding.h"
#include "../tests/tests.h"




int main(void) {

    createBinaryFileOfFileToCompress();

    printf("nb 1 : %d\n", numberCharInFile("TextFiles/FileToCompress.txt"));
    printf("nb 2 : %d\n", numberCharInFile("TextFiles/BinaryFile.txt"));


    return EXIT_SUCCESS;
}