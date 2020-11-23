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
    cpy = (char*) malloc(strlen(string) * sizeof(char));

    // Copy
    int i;
    for(i=0; i<strlen(string) ; i++) {
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
            code = (char*) malloc(depthOfHuffmanTree(tree) * sizeof(char));
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


// void printDictionaryInFile(HuffmanTree tree) {
//     FILE *file = NULL;

//     file = fopen("TextFiles/HuffmanDictionary.txt", "w");

//     // If the file is opened correctly
//     if (file != NULL) {

//         printDictionary(file, tree, NULL, 0);

//         fclose(file);

//     }
//     // If the file is not opened correctly
//     else {
//         displayErrorMessageOpenFile();
//     }
// }












// *********FOR DECOMPRSSION**************




// int sizeOfLineFile(FILE *file) {
//     int size = 0;
//     int n = fgetc(file);
//     while (n != EOF && n != '/') {
//         size++;
//         n = fgetc(file);
//     }
//     return size;
// }


// int countSlashFile(FILE* file)
// {
//     int n;
//     int line = 0;
//     while ((n = fgetc(file)) != EOF) {
//         if (n == '/') {
//             line++;
//         }
//     }
//     fseek(file, 0, SEEK_SET);
//     return line;
// }



// DicoNode *readDictionary(int **returnline) {
//     FILE *filedico = fopen("../TextFiles/HuffmanDictionary.txt", "r");
//     if (filedico != NULL) {

//         int lines = countSlashFile(filedico);
//         DicoNode *dico = (DicoNode *) malloc(lines * sizeof(DicoNode));
//         int i;
//         for (i = 0; i < lines; i++) {
//             dico[i].sizecode = sizeOfLineFile(filedico) - 1;
//         }

//         fseek(filedico, 0, SEEK_SET);
//         readCodeDictionary(filedico, dico);
//         fclose(filedico);

//         *returnline = &lines;
//         printf("%d\n", **returnline);
//         return dico;
//     } else {
//         displayErrorMessageOpenFile();
//     }
// }

// void readCodeDictionary(FILE *filedico, DicoNode *dico) {
//     int actual = fgetc(filedico);
//     int i = 0;
//     int j;
//     while (actual != EOF) {
//         dico[i].letter = actual;
//         dico[i].code.nb = (int*) malloc(dico[i].sizecode * sizeof(int));
//         j = 0;
//         do{
//             actual = fgetc(filedico);
//             actual -= 48;
//             dico[i].code.nb[j] = actual;
//             printf("actual : %c\n", actual+48);
//             j++;
//         }while (actual+48 != 47);
//         i++;
//         actual = fgetc(filedico);
//     }
// }

// void printDicoNode(DicoNode* dico, int lines) {
//     int i = 0;
//     int j;
//     printf("Size = %d", lines);
//     printf("DicoNode :\n");
//     while (i != lines) {
//         printf("%d : ", dico[i].letter);
//         for (j = 0; j < dico[i].sizecode; j++) {
//             printf("%d", dico[i].code.nb[j]);
//         }
//         printf("\n");
//         i++;
//     }
// }
