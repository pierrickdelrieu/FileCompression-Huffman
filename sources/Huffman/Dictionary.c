#include <stdio.h>
#include <stdlib.h>
#include "../../include/Huffman/Dictionary.h"
#include "../../include/IHMCompressor/Show.h"

char* add_char_to_new_string(char* c, char s, int size) {
    size++;
    char* new_c = (char*)malloc(size * sizeof(char));
    int i;
    for (i = 0; i < size - 1; i++) {
        new_c[i] = c[i];
    }
    new_c[i] = s;
    return new_c;
}

void print_to_file( char* code, char letter, int sizecode, FILE* file) {
    fprintf(file, "%c:", letter);
    for (int i = 0; i < sizecode; i++)
    {
        fprintf(file, "%c", code[i]);
    }
    fprintf(file, '\n');
}

void create_dictionary(HuffmanNode* huffman) {
    
    if (huffman != NULL) {
        FILE* dictionary = fopen("../../TextFiles/HuffmanDictionary.txt", "w+");
        int sizecode = 1;
        print_dictionary(huffman->left, "0", sizecode, dictionary);
        print_dictionary(huffman->right, "1", sizecode, dictionary);
        int returnCode = fclose(dictionary);
        if (returncode == EOF)
            printf("Erreur lors de la fermeture du fichier.\n");
        free(code);
    }
    
}

void print_dictionary(HuffmanNode* huffman, char* code, int sizecode, FILE* file) {

    if (huffman != NULL) {
        if (huffman->left == NULL && huffman->right == NULL)
            print_to_file(code, huffman->letter, sizecode, file);
        else {
            char* code1 = add_char_to_new_string(code, '0', sizecode++);
            char* code2 = add_char_to_new_string(code, '1', sizecode++);
            print_dictionary(huffman->left, code1, sizecode + 1);
            print_dictionary(huffman->right, code2, sizecode + 1);
            free(code1);
            free(code2);
        }
    }
}