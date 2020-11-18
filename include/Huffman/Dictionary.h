#include "HuffmanTree.h"
#include "../FileManagment.h"
#include <stdlib.h>
#include <stdio.h>

#ifndef DICTIONARY
#define DICTIONARY

typedef struct DicoNode {
	Binary code;
	char letter;
	int sizecode;
}DicoNode;


char* addCharToNewString(char* c, char s, int size);
int countSlashFile(FILE* file);
int sizeOfLineFile(FILE* file);

void printDictionary(HuffmanNode* huffman, char* code, int sizecode, FILE* file);

DicoNode* readDictionary(int** returnline);
void readCodeDictionary(FILE* filedico, DicoNode* dico);

void printDicoNode(DicoNode* dico, int lines);


#endif // !DICTIONARY