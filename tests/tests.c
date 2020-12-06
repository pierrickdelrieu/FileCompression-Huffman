/**
 * @file tests.c
 * @author Pierrick Delrieu - Benjamin Lesieux - Harold Molter - Faustin Dewas
 * @brief function test of project
 * @version 0.3
 * @date 07-11-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "../include/FileManagment.h"
#include "../include/DataStructures/LinkedList.h"
#include "../include/DataStructures/Queue.h"
#include "../include/Huffman/HuffmanTree.h"
#include "../include/Huffman/Dictionary.h"
#include "../include/Huffman/Decoding.h"
#include "../include/Huffman/Encoding.h"


// static void displayDicoTree(DicoTree tree){
//     if (tree != NULL){
//         displayDicoTree(tree->left);
//         displayDicoTree(tree->right);
//         printf("(%c - %s)", tree->letter, tree->code);
//     }
// }


// static void displayQueue(Queue *queue) {
//     Node *head = queue->last;
//     while (head != NULL) {
//         printf("(%c | %d) -> ", head->data->letter, head->data->occ);
//         head = head->next;
//     }
// }


// static void displayLinkedList(LinkedList l) {
//     Node *head = l;
//     while (head != NULL) {
//         printf("(%c | %d) -> ", head->data->letter, head->data->occ);
//         head = head->next;
//     }
// }

// static void displayTree(HuffmanTree tree) {
//     if (tree != NULL) {
//         printf("\n (%d | %d) ", tree->letter, tree->occ);
//         displayTree(tree->left);
//         displayTree(tree->right);
//     }
// }


/**
 * @brief FileManagement function test (part 1 of project)
 * 
 * @return int 1 if test ok and 0 else
 */
int test_FileManagment(void) {
    int nbCaraFileToCompress = 103;

    initFileToCompress("Alice was beginning to get very tired of sitting by her sister on the bank, and of having nothing to do");

    createBinaryFileOfFileToCompress();

    if ((numberCharInFile("../TextFiles/FileToCompress.txt") == nbCaraFileToCompress) ||
        (numberCharInFile("../TextFiles/BinaryFile.txt") == nbCaraFileToCompress * SIZE_BINARY)) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * @brief LinkedList function test (part 2 of project)
 *
 * @return int 1 if test ok and 0 else
 */
int test_LinkedList(void) {
    LinkedList head = createNode(createHuffmanNode((int) 'b', 4));
    addNode(&head, createNode(createHuffmanNode((int) 'e', 2)));
    addNode(&head, createNode(createHuffmanNode((int) 'n', 8)));

    // size is supposed to be 3
    if (getSize(head) != 3) return 0;

    // we are supposed to find 'b'
    if (find(head, 'b') == NULL) return 0;

    // we are not supposed to find 'h'
    if (find(head, 'h') != NULL) return 0;

    removeNode(&head, head->data);
    removeNode(&head, head->next->data);

    addNode(&head, createNode(createHuffmanNode((int) 'o', 2)));

    // size is supposed to be 2
    if (getSize(head) != 2) return 0;

    return 1;
}


/**
 * @brief OccQueue function test
 * 
 * @return int 1 if test ok and 0 else
 */
int test_Queue_Occ(void) {
    initFileToCompress("Ceci est un test unitaire visant à regarder si la queue est bien triée, c'est à dire dans l'ordre décroissant d'occ.");
    Queue* queue = createSortOccQueue();
    Node* temp = queue->last;
    while (temp != queue->first)
    {
        if (temp->data->occ < temp->next->data->occ) return 0;
        temp = temp->next;
    }
    return 1;
}


/**
 * @brief Queue function test (part 2 of project)
 * @details Test with queue NULL and not NULL
 *
 * @return int 1 if test ok and 0 else
 */
int test_Queue(void) {
    // INPUT
    HuffmanNode* last = createHuffmanNode((int) 'n', 2);
    LinkedList head1 = createNode(last);
    LinkedList head3 = createNode(createHuffmanNode((int) 'b', 8));
    addNode(&head3, createNode(createHuffmanNode((int) 'e', 4)));
    addNode(&head3, createNode(last));
    LinkedList input[3] = {NULL, head1, head3}; 

    // TEST
    int i;
    for(i=0; i<3; i++) {
        // Initialisation
        Queue* f = initQueue();
        f->last = input[i];
        if(input[i] == NULL) {
            f->first = input[i];
        }
        else {
            while(input[i]->next != NULL) {
                input[i] = input[i]->next;
            }
            f->first = input[i];
        }


        // Vérification des tests
        HuffmanNode* node = createHuffmanNode((int) 'a', 3);
        if(input[i] == NULL) {
            if(pullQueue(&f) != NULL) {
                return 0;
            }
            if(pushQueue(&f, node) != 1) {
                return 0;
            }
            if((pullQueue(&f) != node) || (f->last != NULL) || (f->first != NULL)) {
                return 0;
            }
        }
        else {
            if(pushQueue(&f, node) != 1) {
                return 0;
            }
            if(pullQueue(&f) != last) {
                return 0;
            }
        }
    }

    return 1;

}


/**
 * @brief Creating a Huffman tree with the two-queue process
 * @details Verification of the tree obtained using: https://csfieldguide.org.nz/en/interactives/huffman-tree/
 * 
 * @return int Returns 1 all the time if there is no error during execution
 */
int test_HuffmanTree(void) {
    initFileToCompress("je m'appelle aristote");
    // Queue* occQueue = createSortOccQueue();
    // HuffmanTree tree = createHuffmanTree(occQueue);
    // displayTree(tree);

    // a comparer avec le lien en documentation
    return 1;
}



int test_dictionary() {

    Queue* occQueue = createSortOccQueue();
    //printf("\nWe have the following Queue : ");
    //displayQueue(occQueue);

    HuffmanTree tree = createHuffmanTree(occQueue);
    //displayTree(tree);

    DicoTree dicoTree = NULL;
    dicoTree = createDicoTree(tree);
    // displayDicoTree(dicoTree);

    initDictionaryPrinting(dicoTree);
    return 1;
}


/**
 * @brief Compare FileToCompress.txt and HuffmanDecompression.txt
 * 
 * @return int 1 if test ok and 0 else
 */
int test_decompression(void) {

    initFileToCompress("Ceci est un test fonctionnel visant à regarder si la décompression se passe bien, autrement dit, que les deux fichiers textes coïncident.");
    Queue* occQueue = createSortOccQueue();
    HuffmanTree tree = createHuffmanTree(occQueue);
    DicoTree dicoTree = createDicoTree(tree);
    encodingFile(dicoTree);
    initDictionaryPrinting(dicoTree);

    freeNode(occQueue->last);
    free(occQueue);
    freeHuffmanTree(tree);
    freeDicoTree(dicoTree);

    decodeFile();

    FILE* compressed = fopen("TextFiles/FileToCompress.txt", "r");
    FILE* decompressed = fopen("TextFiles/HuffmanDecompression.txt", "r");

    int c1 = fgetc(compressed);
    int c2 = fgetc(decompressed);

    int line = 0;

    while (c1 != EOF) {
        if (c1 != c2) {
            printf("\n not cool c1 : %c , c2 : %c", c1, c2);
            fclose(compressed);
            fclose(decompressed);

            printf("\n%d", line);
            return 0;
        }

        if (c1 == EOF && c2 == EOF) break;
        else if (c1 == EOF) return 0;
        else if (c2 == EOF) return 0;

        if (c1 == '\n' && c2 == '\n') line++;

        c1 = fgetc(compressed);
        c2 = fgetc(decompressed);
    }

    fclose(compressed);
    fclose(decompressed);

    return 1;
}


/**
 * @brief Verif ratiocompression
 * 
 * @return int 1 if test ok and 0 else
 */
int test_encoding(void) {
    initFileToCompress("Ceci est un test fonctionnel visant à regarder si la compression se passe bien, si elle est acceptable (au delà de 20 prcts).");
    Queue* occQueue = createSortOccQueue();
    HuffmanTree tree = createHuffmanTree(occQueue);
    DicoTree dicoTree = createDicoTree(tree);
    encodingFile(dicoTree);
    initDictionaryPrinting(dicoTree);

    freeNode(occQueue->last);
    free(occQueue);
    freeHuffmanTree(tree);
    freeDicoTree(dicoTree);

    float ratio = ratioCompression();
    if (ratio < 20) {
        return 0;
    }
    return 1;
}