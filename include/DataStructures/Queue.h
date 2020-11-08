#ifndef QUEUE
#define QUEUE

#include "../../include/DataStructures/LinkedList.h"

/**
 * @brief Structure containing the start and end node of the list. Queue allows you to manage items like a queue. 
 * LIFO : Last In First Out
 * 
 */
typedef struct Queue {
    Node* start;
    Node* end;
} Queue;



void    initQueue     (Queue** f);
int     pushQueue     (Queue** f, Node* nx_elem);
Node*   pullQueue     (Queue** f);


#endif // !QUEUE
