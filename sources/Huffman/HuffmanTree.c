#include <stdio.h>
#include <stdlib.h>
#include "../../include/Huffman/HuffmanTree.h"
#include "../../include/IHMCompressor/Show.h"

static HuffmanTree createLeaf(int letter) {

    HuffmanTree tree = (HuffmanTree*) malloc(sizeof(HuffmanTree));

    if (tree != NULL) {
        tree->letter = letter;
        tree->occ = occ;

        return tree;
    }

    else {
        displayErrorMemoryAllocation();
    }
}


HuffmanTree createHuffmanTreeFromOccList(LinkedList occList) {

}