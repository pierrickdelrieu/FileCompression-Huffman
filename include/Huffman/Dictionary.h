#include "HuffmanTree.h"
#include <stdlib.h>
#include <stdio.h>

#ifndef DICTIONARY
#define DICTIONARY

void add_char_to_string(char* s, char c, int size);
void print_dictionary(Leaf* huffman);
void print_to_file(int size, char* s, char c, FILE* file);

#endif // !DICTIONARY