#ifndef LINKED_LIST
#define LINKED_LIST

/***
 * @brief Defines the node of a doubly linked list
 * @details as this structure will be used as the Node of an HuffmanTree,
 * the pointers right and left are named after the property the list will
 * have in the future. When used as a doubly linked list, right means 'next'
 * and left means 'previous'
 */
typedef struct Node {
    int letter;
    int occ;
    struct Node* right;
    struct Node* left;
} Node;

///@brief Defines the pointer of a doubly linked list
typedef Node* LinkedList;

Node*      createNode     (int letter, int occ);

void       addNode        (LinkedList* list, Node* node);

void       removeNode     (LinkedList* list, int letter);

Node*      find           (LinkedList list, int letter);

int        getSize        (LinkedList list);

void       printList      (LinkedList list);

#endif // !LINKED_LIST
