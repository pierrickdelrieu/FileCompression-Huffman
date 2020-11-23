#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/Huffman/Dictionary.h"
#include "../../include/IHMCompressor/Show.h"


static char* copyString(char* string) {
    char* cpy = NULL;
    cpy = (char*) malloc(strlen(string) * sizeof(char));

    int i;
    for(i=0; i<strlen(string) ; i++) {
        cpy[i] = string[i];
    }

    return cpy;
}


DicoNode* createDicoNode(int letter, char* code) {
    DicoNode* x = NULL;
    x = (DicoNode*) malloc(sizeof(DicoNode));

    x->letter = letter;
    x->code = code;
    x->left = NULL;
    x->right = NULL;

    return x;
}


int depthOfTree(DicoTree tree) {
    if (tree == NULL) {
        return 0;
    } 
    else {
        int leftDepth = depthOfTree(tree->left);
        int rightDepth = depthOfTree(tree->right);
        if (leftDepth > rightDepth) {
            return 1 + leftDepth;
        }
        else{
            return 1 +rightDepth;
        }
    }
}

int getBalanceFactor(DicoTree tree) {
    if(tree == NULL) {
        return 0;
    }
    else {
        return depthOfTree(tree->right) - depthOfTree(tree->left);
    }
}

void rightRotation(DicoTree* tree){
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
        balanceTree(&((*tree)->left));// Postfix
        balanceTree(&((*tree)->right));
        
        int balance_factor = getBalanceFactor(*tree);
        if (balance_factor <= -2){// Cas Gauche - ??
            if(getBalanceFactor((*tree)->left) > 0){// Gauche - Droite
                leftRotation(&((*tree)->left));
            }
            rightRotation(tree);// Gauche - Gauche
        }
        else if (balance_factor >= 2){// Cas Droite - ??
            if(getBalanceFactor((*tree)->right) < 0){// Droite - Gauche
                rightRotation(&((*tree)->right));
            }
            leftRotation(tree);// Droite - Droite
        }
    }
}

void addNodeBST(DicoTree* tree, int letter, char* code){
    if(*tree == NULL){
        *tree = createDicoNode(letter, code);
    }
    else{
        if (strlen((*tree)->code) > strlen(code)){
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



char *addCharString(char *c, char s, int size) {

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


DicoTree createDicoTree(HuffmanTree tree) {
    DicoTree avl = NULL;

    if (tree != NULL) {
        if (tree->left == NULL && tree->right == NULL) {
            avl = createDicoNode(tree->letter, "0");
        }
        else {
            initDicoTree(&avl, tree, NULL, 0);
        }
    }

    return avl;
}

void initDicoTree(DicoTree* avl, HuffmanTree tree, char *code, int sizecode) {
    if (tree != NULL) {

        // condition d'arret
        if (tree->left == NULL && tree->right == NULL) {
            code[sizecode] = '\0';
            if(avl == NULL) {
                *avl = createDicoNode(tree->letter, copyString(code));
            }
            else {
                addNodeAVL(avl, tree->letter, copyString(code));
            }
        } 

        else {
            if (tree->left != NULL) {
                char* code1 = addCharString(code, '0', sizecode);
                initDicoTree(avl, tree->left, code1, sizecode + 1);
                free(code1);
            }
            if (tree->right != NULL) {
                char *code2 = addCharString(code, '1', sizecode);
                initDicoTree(avl, tree->right, code2, sizecode + 1);
                free(code2);
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
        printDictionaryFile(dicoTree->left, file);
        fprintf(file, "%c%s/", dicoTree->letter, dicoTree->code);
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
