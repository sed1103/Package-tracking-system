#ifndef NODE_H
#define NODE_H

#include "Package.h"

/**
 * @file Node.h
 * @brief Definition of the Node structure.
 */

/**
 * @struct Node
 * @brief Represents a node in the hash table.
 */
typedef struct Node {
    Package package; /**< Package stored in the node. */
    struct Node* next; /**< Pointer to the next node. */
} Node;

#endif // NODE_H
