#ifndef DICTIONARY
#define DICTIONARY

#include "HuffmanTree.h"
#include "../FileManagment.h"

typedef struct DicoNode {
	char* code; 
	int letter;
	struct DicoNode* left;
	struct DicoNode* right;
} DicoNode;

DicoNode* createDicoNode(int letter, char* code);

typedef DicoNode* DicoTree; // AVL

int 	depthOfTree			(DicoTree tree);
int 	getBalanceFactor	(DicoTree tree);
void 	leftRotation		(DicoTree* tree);
void 	rightRotation		(DicoTree* tree);
void 	balanceTree			(DicoTree* tree);
void 	addNodeBST			(DicoTree* tree, int letter, char* code);
void 	addNodeAVL			(DicoTree* tree, int letter, char* code);



DicoTree	createDicoTree			(HuffmanTree tree);
void		initDicoTree			(DicoTree* avl, HuffmanTree tree, char *code, int sizecode) ;
char*		addCharString			(char* c, char s, int size);
void		initDictionaryPrinting	(DicoTree dicoTree);
void		printDictionaryFile		(DicoTree dicoTree, FILE* file);


#endif // !DICTIONARY