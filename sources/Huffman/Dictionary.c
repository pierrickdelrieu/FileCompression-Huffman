/**
 * @file Dictionary.c
 * @author Pierrick Delrieu - Faustin Dewas
 * @brief Creation of a dictionary with each letter and its binary code compressed
 * @version 0.1
 * @date 23-11-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

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


/**
 * @brief Create a DicoNode 
 * 
 * @param letter Node field
 * @param code Node field
 * @return DicoNode* Address of the created node
 */
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


/**
 * @brief Depth of DicoTree
 * 
 * @param tree Tree whose depth is to be found
 * @return int Depth of Tree
 */
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


/**
 * @brief Get the Balance Factor of DicoNode
 * 
 * @param tree 
 * @return int 
 */
int getBalanceFactor(DicoNode*  tree) {
    if(tree == NULL) {
        return 0;
    }
    else {
        return depthOfDicoTree(tree->right) - depthOfDicoTree(tree->left);
    }
}


/**
 * @brief RightRotation of Node
 * 
 * @param tree Node at the origin of the rotation
 */
void rightRotation(DicoNode** tree){
    if (*tree != NULL){
        DicoNode* temp = (*tree)->left;
        (*tree)->left = temp->right;
        temp->right = *tree;
        *tree = temp;
    }
}


/**
 * @brief LeftRotation of Node
 * 
 * @param tree Node at the origin of the rotation
 */
void leftRotation(DicoTree* tree){
    if (*tree != NULL){
        DicoNode* temp = (*tree)->right;
        (*tree)->right = temp->left;
        temp->left = *tree;
        *tree = temp;
    }
}


/**
 * @brief Tree balance
 * 
 * @param tree Tree Balanced
 */
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
        // if (strlen((*tree)->code) > strlen(code)){
        //     addNodeBST(&((*tree)->left), letter, code);
        // }
        // else{
        //     addNodeBST(&((*tree)->right), letter, code);
        // }
        if ((*tree)->letter > letter){
            addNodeBST(&((*tree)->left), letter, code);
        }
        else{
            addNodeBST(&((*tree)->right), letter, code);
        }
    }
}

/**
 * @brief Adding a node to a balanced binary search tree
 * @details Binary trees sort by code size
 * 
 * @param tree 
 * @param letter 
 * @param code 
 */
void addNodeAVL(DicoTree* tree, int letter, char* code){
    addNodeBST(tree, letter, code);
    balanceTree(tree);
}

/**
 * @brief Create a Dico Tree object
 * 
 * @param tree Huffman tree to retrieve the codes
 * @return DicoTree Balanced binary search tree containing these letters with its code
 */
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


/**
 * @brief Recursive function which initializes the tree containing each letter and its code
 * 
 * @param avl Avl to create
 * @param tree Huffman tree from which the AVL is created
 * @param code Initialized when calling the function
 * @param sizecode Initialized when calling the function at 0
 */
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


/**
 * @brief Function that opens and calls the recursive function to create the dictionary file
 * 
 * @param dicoTree AVL containing letters and codes
 */
void initDictionaryPrinting(DicoTree dicoTree) {
    FILE* file = fopen("TextFiles/HuffmanDictionary.txt", "w+");
    printDictionaryFile(dicoTree, file);
    fclose(file);
}


/**
 * @brief Recursive function which writes the code of each letter in the text file
 * 
 * @param dicoTree AVL containing letters and codes
 * @param file File to write to (previously opened)
 */
void printDictionaryFile(DicoTree dicoTree, FILE* file) {
    if (dicoTree != NULL) {
        fprintf(file, "%c%s/", dicoTree->letter, dicoTree->code);
        printDictionaryFile(dicoTree->left, file);
        printDictionaryFile(dicoTree->right, file);
    }
}

/**
 * @brief Memory release
 * 
 * @param tree Tree has to free memory because dynamically allocated
 */
void freeDicoTree(DicoTree tree) {
    if(tree != NULL) {
        freeDicoTree(tree->left);
        freeDicoTree(tree->right);
        free (tree);
    }
}








