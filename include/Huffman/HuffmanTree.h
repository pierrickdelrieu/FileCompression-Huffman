#ifndef HUFFMAN_TREE
#define HUFFMAN_TREE


typedef struct Leaf {
    int letter;
    int occ;
    struct Leaf* left;
    struct Leaf* right;
} Leaf;

typedef Leaf* LeafsList;
typedef Leaf* HuffmanTree;

Leaf* createLeaf(int letter, int occ);
void deletingLeaf(LeafsList* leafslist, Leaf* elem);
Leaf* elementWithSmallestOccurrence(LeafsList leafslist);
void addLeafToTheEndOfLeafsList(LeafsList leafslist, Leaf* elem);


HuffmanTree createHuffmanTree(LeafsList* leafslist);


#endif // !HUFFMAN_TREE