#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/Huffman/Dictionary.h"
#include "../../include/IHMCompressor/Show.h"


/**
 * @brief Copy a string and return its address
 * 
 * @param string String to copy
 * @return char* Copied string
 */
static char* copyString(char* string) {
    // Allocation
    char* cpy = NULL;
    cpy = (char*) malloc(strlen(string)+1 * sizeof(char));

    // Copy
    int i;
    for(i=0; i<strlen(string)+1 ; i++) {
        cpy[i] = string[i];
    }


    return cpy;
}



DicoNode* createDicoNode(int letter, char* code) {
    // Allocation
    DicoNode* x = NULL;
    x = (DicoNode*) malloc(sizeof(DicoNode));

    // Initialization
    x->letter = letter;
    x->code = code;
    x->left = NULL;
    x->right = NULL;

    return x;
}



int depthOfDicoTree(DicoTree tree) {
    if (tree == NULL) {
        return 0;
    } 
    else {
        int leftDepth = depthOfDicoTree(tree->left);
        int rightDepth = depthOfDicoTree(tree->right);
        if (leftDepth > rightDepth) {
            return 1 + leftDepth;
        }
        else{
            return 1 +rightDepth;
        }
    }
}



int getBalanceFactor(DicoNode*  tree) {
    if(tree == NULL) {
        return 0;
    }
    else {
        return depthOfDicoTree(tree->right) - depthOfDicoTree(tree->left);
    }
}



void rightRotation(DicoNode** tree){
    if (*tree != NULL){
        DicoNode* temp = (*tree)->left;
        (*tree)->left = temp->right;
        temp->right = *tree;
        *tree = temp;
    }
}



void leftRotation(DicoTree* tree){
    if (*tree != NULL){
        DicoNode* temp = (*tree)->right;
        (*tree)->right = temp->left;
        temp->left = *tree;
        *tree = temp;
    }
}



void balanceTree(DicoTree* tree){
    if (*tree != NULL){
        balanceTree(&((*tree)->left));
        balanceTree(&((*tree)->right));
        
        int balance_factor = getBalanceFactor(*tree);

        // Case Left - ...
        if (balance_factor <= -2) {
            // Case Left - Right
            if(getBalanceFactor((*tree)->left) > 0) {
                leftRotation(&((*tree)->left));
            }
            // Case Left - Left
            rightRotation(tree);
        }

        // Case Right - ...
        else if (balance_factor >= 2) {
            // Case Right - Left
            if(getBalanceFactor((*tree)->right) < 0) {
                rightRotation(&((*tree)->right));
            }
            // Case Right - Right
            leftRotation(tree);
        }
    }
}


static void addNodeBST(DicoTree* tree, int letter, char* code){
    if(*tree == NULL){
        *tree = createDicoNode(letter, code);
    }
    else{
        
        if ((*tree)->letter > letter){
            addNodeBST(&((*tree)->left), letter, code);
        }
        else{
            addNodeBST(&((*tree)->right), letter, code);
        }
    }
}


void addNodeAVL(DicoTree* tree, int letter, char* code){
    addNodeBST(tree, letter, code);
    balanceTree(tree);
}


DicoTree createDicoTree(HuffmanTree tree) {
    DicoTree avl = NULL;

    // If File To Compress contains characters
    if (tree != NULL) {
        // If File To Compress contains one character
        if (tree->left == NULL && tree->right == NULL) {
            avl = createDicoNode(tree->letter, "0");
        }
        else {
            char* code = NULL;
            code = (char*) malloc(depthOfHuffmanTree(tree)+1 * sizeof(char));
            int i;
            for(i=0; i<depthOfHuffmanTree(tree); i++) {
                code[i] = '0';
            }
            initDicoTree(&avl, tree, code, 0);
            free(code);
        }
    }

    return avl;
}



void initDicoTree(DicoTree* avl, HuffmanTree tree, char* code, int sizecode) {
    if (tree != NULL) {

        // condition d'arret
        if (tree->left == NULL && tree->right == NULL) {
            code[sizecode] = '\0'; // add end of string

            // If this is AVL's first node
            if(avl == NULL) {
                *avl = createDicoNode(tree->letter, copyString(code));
            }
            else {
                addNodeAVL(avl, tree->letter, copyString(code));
            }
        } 

        else {
            if (tree->left != NULL) {
                code[sizecode] = '0';
                initDicoTree(avl, tree->left, code, sizecode + 1);
            }
            if (tree->right != NULL) {
                code[sizecode] = '1';
                initDicoTree(avl, tree->right, code, sizecode + 1);
            }
        }
    }
}



void initDictionaryPrinting(DicoTree dicoTree) {
    FILE* file = fopen("TextFiles/HuffmanDictionary.txt", "w+");
    printDictionaryFile(dicoTree, file);
    fclose(file);
}



void printDictionaryFile(DicoTree dicoTree, FILE* file) {
    if (dicoTree != NULL) {
        fprintf(file, "%c%s/", dicoTree->letter, dicoTree->code);
        printDictionaryFile(dicoTree->left, file);
        printDictionaryFile(dicoTree->right, file);
    }
}


void freeDicoTree(DicoTree tree) {
    if(tree != NULL) {
        freeDicoTree(tree->left);
        freeDicoTree(tree->right);
        free (tree);
    }
}








