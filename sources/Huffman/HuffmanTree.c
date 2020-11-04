#include <stdio.h>
#include <stdlib.h>
#include "../../include/Huffman/HuffmanTree.h"
#include "../../include/IHMCompressor/Show.h"


Leaf* createLeaf(int letter, int occ) {
    Leaf* x = NULL;

    x->letter = letter;
    x->occ = occ;
    x->left = NULL;
    x->right = NULL;

    return x;
}


void deletingLeaf(LeafsList* leafslist, Leaf* elem) {

}




HuffmanTree createHuffmanTree(LeafsList* leafslist) {
    if(leafslist == NULL) {
        return NULL;
    }
    else {
        HuffmanTree tree = NULL;
        Leaf* elem1 = NULL;
        Leaf* elem2 = NULL;

        while(*leafslist != NULL) {

            // Récupération des deux éléments ayant la plus petite occurrence
            elem1 = ElementWithSmallestOccurrence(*leafslist);
            deletingLeaf(leafslist, elem1);

            elem2 = ElementWithSmallestOccurrence(*leafslist);
            deletingLeaf(leafslist, elem2);


            // création du noeud
            tree = createLeaf(-1, elem1->occ + elem2->occ);
            tree->left = elem1;
            tree->right = elem2;


            // ajout de l'element a liste feuille
            addLeafToTheEndOfLeafsList(*leafslist, tree);

        }
    }
}
