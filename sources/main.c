#include <stdio.h>
#include <stdlib.h>
#include "../include/FileManagment.h"
#include "../include//Huffman/Encoding.h"
#include "../include//Huffman/Decoding.h"




int main() {

    create_binary_file_of_FileToCompress();

    printf("nb 1 : %d\n", number_char_in_file("TextFiles/FileToCompress.txt"));
    printf("nb 2 : %d\n", number_char_in_file("TextFiles/BinaryFile.txt"));


    return EXIT_SUCCESS;
}