#include "HuffmanTree.h"
#include <stdlib.h>
#include <stdio.h>

#ifndef DICTIONARY
#define DICTIONARY

typedef struct DicoNode {
	char* code;	//Binary
	char letter;
	int sizecode;
}DicoNode;


char* addCharToNewString(char* c, char s, int size);
int countSlashFile(FILE* file);
int sizeOfLineFile(FILE* file);

void printDictionaryOnFile(HuffmanNode* huffman, char* code, int sizecode, FILE* file);

DicoNode* createDicoNode(int** returnline);
void readDictionary(FILE* filedico, DicoNode* dico);

void printDicoNode(DicoNode* dico, int lines);


#endif // !DICTIONARY