#ifndef FILE
#define FILE

#include "../../include/DataStructures/LinkedList.h"

/**
 * @brief Structure containing the start and end node of the list. File (queue) allows you to manage items like a queue. 
 * LIFO : Last In First Out
 * 
 */
typedef struct File {
    Node* start;
    Node* end;
} File;



void    initFile    (File** f);
int     enfiler     (File** f, Node* nx_elem);
Node*   defiler     (File** f);


#endif // !FILE
