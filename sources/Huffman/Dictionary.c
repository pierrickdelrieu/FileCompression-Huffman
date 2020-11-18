#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/Huffman/Dictionary.h"
#include "../../include/IHMCompressor/Show.h"

char *addCharToNewString(char *c, char s, int size) {

    if (c != NULL) {
        size++;
        char* new_c = (char*)malloc(size * sizeof(char));
        int i;
        for (i = 0; i < size - 1; i++) {
            new_c[i] = c[i];
        }
        new_c[i] = s;
        return new_c;
    }
    else {
        char* new_c = (char*)malloc(sizeof(char));
        new_c[0] = s;
        return new_c;
    }
    
}

int sizeOfLineFile(FILE *file) {
    int size = 0;
    int n = fgetc(file);
    while (n != EOF && n != '/') {
        size++;
        n = fgetc(file);
    }
    return size;
}


int countSlashFile(FILE* file)
{
    int n;
    int line = 0;
    while ((n = fgetc(file)) != EOF) {
        if (n == '/') {
            line++;
        }
    }
    fseek(file, 0, SEEK_SET);
    return line;
}

void printDictionaryOnFile(HuffmanNode *huffman, char *code, int sizecode, FILE* file) {
    printf("\nEntering");

    if (huffman != NULL) {
        if (huffman->left == NULL && huffman->right == NULL) {
            printf("\nActual code : %s", code);
            fprintf(file, "%c:", huffman->letter);
            for (int i = 0; i < sizecode; i++) {
                fprintf(file, "%c", code[i]);
            }
            fprintf(file, "/");

        } else {

            if (huffman->left != NULL) {
                char *code1 = addCharToNewString(code, '0', sizecode);
                printDictionaryOnFile(huffman->left, code1, sizecode + 1, file);
                free(code1);
            }
            if (huffman->right != NULL) {
                char *code2 = addCharToNewString(code, '1', sizecode);
                printDictionaryOnFile(huffman->right, code2, sizecode + 1, file);
                free(code2);
            }
        }
    }
}

DicoNode *createDicoNode(int **returnline) {
    FILE *filedico = fopen("../TextFiles/HuffmanDictionary.txt", "r");
    if (filedico != NULL) {

        int lines = countSlashFile(filedico);
        DicoNode *dico = (DicoNode *) malloc(lines * sizeof(DicoNode));
        int i;
        for (i = 0; i < lines; i++) {
            dico[i].sizecode = sizeOfLineFile(filedico) - 2;
        }

        fseek(filedico, 0, SEEK_SET);
        readDictionary(filedico, dico);
        fclose(filedico);

        *returnline = &lines;
        printf("%d\n", **returnline);
        return dico;
    } else {
        displayErrorMessageOpenFile();
    }
}

void readDictionary(FILE *filedico, DicoNode *dico) {
    int actual = fgetc(filedico);
    int i = 0;
    int j;
    while (actual != EOF) {
        dico[i].letter = actual;
        dico[i].code = (char *) malloc(dico[i].sizecode * sizeof(char));
        j = 0;
        actual = fgetc(filedico);                //On ne veut pas du ":"
        while (actual != '/') {
            actual = fgetc(filedico);
            dico[i].code[j] = actual;
            j++;
        }
        i++;
        actual = fgetc(filedico);
    }
}

void printDicoNode(DicoNode *dico, int lines) {
    int i = 0;
    int j;
    printf("DicoNode :\n");
    while (i != lines) {
        printf("%c : ", dico[i].letter);
        for (j = 0; j < dico[i].sizecode; j++) {
            printf("%c", dico[i].code[j]);
        }
        printf("\n");
        i++;
    }
}

void printString(char *c, int size) {
    for (int i = 0; i < size; i++) {
        printf("%c", c[i]);
    }
    printf("\n");
}