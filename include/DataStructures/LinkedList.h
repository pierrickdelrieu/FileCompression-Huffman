/**
 * @file LinkedList.h
 * @author Benjamin Lesieux - Harold Molter
 * @brief All the basic functions of a linked list
 * @details Part 2 of project
 * @version 1.0
 * @date 09-11-20
 *
 * @copyright Copyright (c) 2020
 *
 */

#ifndef LINKED_LIST
#define LINKED_LIST

/***
 * @brief Defines the node of a doubly linked list
 * @details as this structure will be used as the Node of an HuffmanTree,
 * the pointers right and left are named after the property the list will
 * have in the future. When used as a doubly linked list, right means 'next'
 * and left means 'previous'
 */
typedef struct HuffmanNode {
    int letter;
    int occ;
    struct HuffmanNode* right;
    struct HuffmanNode* left;
} HuffmanNode;

typedef struct Node {
    HuffmanNode* data;
    struct Node* next;
} Node;

///@brief Defines the pointer of a doubly linked list
typedef Node* LinkedList;

/**
 * @brief Creates an HuffmanNode
 * @param letter An integer corresponding to the ascii value of the letter
 * @param occ The number of occurrences of the letter
 *
 * @return HuffmanNode* a pointer to an HuffmanNode
 * */
HuffmanNode*      createHuffmanNode     (int letter, int occ);

/**
 * @brief Creates a node for a doubly linked list
 *
 * @param huffmanNode the data of the Node
 * @return Node* A pointer to a Node
 * */
Node*             createNode            (HuffmanNode* data);

/**
 * @brief Adds a Node to a Doubly Linked List
 * @param list The head of the list (Node*)
 * @param node A pointer to the Node we want to add
 *
 * */
void              addNode               (LinkedList* list, Node* node);

/**
 * @brief Removes an HuffmanNode from a Linked List
 * @param list A pointer to a pointer of the head of the list (Node** or LinkedList*)
 * @param huffmanNode The HuffmanNode we want to delete
 *
 * */
void              removeNode            (LinkedList* list, HuffmanNode* huffmanNode);

/**
 * @brief Search for a Node that contains the letter we are searching for
 * @param list A pointer to the head of the list
 * @param letter The ascii value of the letter to search
 *
 * @return Node* A pointer to the node containing the letter
 * */
Node*             find                  (LinkedList list, int letter);

/**
 * @brief Calculates the size of the linked list
 * @param list A pointer to the head of the list
 *
 * @return int The size of the list
 * */
int               getSize               (LinkedList list);

/**
* @brief  Find Letter with less occurrences
* @param LinkedList
*
* @return Node*
**/
Node*             findMinOccLetter      (LinkedList list);



void              freeNode              (LinkedList list);



#endif // !LINKED_LIST
