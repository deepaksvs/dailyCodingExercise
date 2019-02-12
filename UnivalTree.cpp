//
//    A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.
//
//    Given the root to a binary tree, count the number of unival subtrees.
//
//    For example, the following tree has 5 unival subtrees:
//
//    0
//    / \
//    1   0
//    / \
//    1   0
//    / \
//    1   1

// Not Tested completely

#include <stdio.h>

typedef struct _bnode {
    int val;
    struct _bnode *left;
    struct _bnode *right;
}bnode_t;


int count_unival(bnode_t *root)
{
    int count = 0;
    if (root == NULL) {
        return 0;
    }

    if ((root->left == NULL) && (root->right == NULL)) {
        return 1;
    }

    if ((root->left != NULL) && (root->right != NULL) && (root->left->val == root->right->val)
        && (root->val == root->left->val)) {
        count = 1;
    }
    return count + count_unival(root->left) + count_unival(root->right);
}
