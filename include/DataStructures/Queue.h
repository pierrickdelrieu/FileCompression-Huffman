/**
 * @file Queue.h
 * @author Pierrick Delrieu
 * @brief Management of the linked list with a Queue
 * @version 0.1
 * @date 07-11-2020
 *
 * @copyright Copyright (c) 2020
 *
 */

#ifndef QUEUE
#define QUEUE

#include "../../include/DataStructures/LinkedList.h"

/**
 * @brief Structure containing the first and last node of the list. Queue allows you to manage items like a queue. 
 * FIFO : First In First Out
 * 
 */
typedef struct Queue {
    Node* first;
    Node* last;
} Queue;

/**
 * @brief Initialization of the last and first fields of the fiel and memory allocation
 *
 * @return Queue* address initialized Queue initialized
 */
Queue*          initQueue                       (void);

/**
 * @brief Adding an HuffmanNode to the top of the list
 *
 * @param f Queue adress (modified data) where the HuffmanNode must be added
 * @param nx_elem HuffmanNode to add at the top of the list
 * @return int Return 1 if HuffmanNode has been added and 0 otherwise (if the Queue has not been initialized)
 */
int             pushQueue                       (Queue** f, HuffmanNode* nx_elem);

/**
 * @brief Remove and return the last element in the Queue
 *
 * @param f Queue adress (modified data) where the HuffmanNode must be removed
 * @return HuffmanNode* Removed HuffmanNode
 */
HuffmanNode*    pullQueue                       (Queue** f);



#endif // !QUEUE
