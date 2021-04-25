#ifndef BINARYSORTTREE_BINARY_SORT_TREE_H
#define BINARYSORTTREE_BINARY_SORT_TREE_H

#define true 1
#define false 0
#define succeed 1
#define failed 0
#define SBT_Status int

typedef int BST_ElemType;

typedef struct Node {
    BST_ElemType value;
    struct Node* left, * right;
}Node, * NodePtr;

typedef struct BinarySortTree {
    NodePtr root;
} BinarySortTree, * BinarySortTreePtr;

/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
SBT_Status BST_init(BinarySortTreePtr);


/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
SBT_Status BST_insert(BinarySortTreePtr, BST_ElemType);


/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
SBT_Status BST_delete(NodePtr*, BST_ElemType);

/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
SBT_Status BST_search(BinarySortTreePtr, BST_ElemType);


/**
 * Print the element in the BST
 * @param NodePtr v
 */
void visit(NodePtr);


/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
SBT_Status BST_preorderI(BinarySortTreePtr, void (*visit)(NodePtr));


/**
 * BST preorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
SBT_Status BST_preorderR(BinarySortTreePtr, void (*visit)(NodePtr));
SBT_Status BST_preorderR_(NodePtr, void (*visit)(NodePtr));

/**
 * BST inorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
SBT_Status BST_inorderI(BinarySortTreePtr, void (*visit)(NodePtr));


/**
 * BST inorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
SBT_Status BST_inorderR(BinarySortTreePtr, void (*visit)(NodePtr));
SBT_Status BST_inorderR_(NodePtr, void (*visit)(NodePtr));

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
SBT_Status BST_postorderI(BinarySortTreePtr, void (*visit)(NodePtr));


/**
 * BST postorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
SBT_Status BST_postorderR(BinarySortTreePtr, void (*visit)(NodePtr));
SBT_Status BST_postorderR_(NodePtr, void (*visit)(NodePtr));

/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
SBT_Status BST_levelOrder(BinarySortTreePtr, void (*visit)(NodePtr));


/**
 * Print the menu
 */
void PrintMenu();

/**
 * Clear the BST
 * @param BinarySortTreePtr BST
 * @return is successful
 */
SBT_Status BST_clear(BinarySortTreePtr p);

#endif //BINARYSORTTREE_BINARY_SORT_TREE_H