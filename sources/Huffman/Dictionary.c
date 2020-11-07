#include <stdio.h>
#include <stdlib.h>
#include "../../include/Huffman/Dictionary.h"
#include "../../include/IHMCompressor/Show.h"

void add_char_to_string(char* s, char c, int size) {
    realloc(s, size * sizeof(char));
    s[size - 1] = c;
}

void print_to_file(int size, char* s, char c, FILE* file, int bool) {
    fprintf(file, "%c:", c);
    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%c", s[i]);
    }
    if(bool != 1)
        fprintf(file, "0\n");
    else
        fprintf(file, "\n");
}
void print_dictionary(Leaf* huffman) {

    if (huffman != NULL) {
        FILE* dictionary = fopen("../../TextFiles/HuffmanDictionary.txt", "w+");
        Leaf* temp = huffman;
        int size = 1;
        char* n = (char*)malloc(size * sizeof(char));
        printf('%s', n);
        while (temp->right != NULL)
        {
            printf('%s', n);
            print_to_file(size, n, temp->left->letter, dictionary, 0);
            size++;
            add_char_to_string(n, '1', size);
            temp = temp->right;
        }
        fprintf(dictionary, "%c:%s\n", temp->left->letter, n, 1);
        free(huffman);
        free(n);
    }
}