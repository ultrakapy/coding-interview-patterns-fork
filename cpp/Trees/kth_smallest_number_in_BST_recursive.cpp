#include "ds/TreeNode.h"
using ds::TreeNode;

/**
 * Definition of TreeNode:
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
void kthSmallest(TreeNode* node, int& k, int& smallest) {
    if (!node) return;

    kthSmallest(node->left, k, smallest);

    if (k == 0) return; // short-circuit: answer found in left subtree
    if (--k == 0) {
        smallest = node->val;
        return;
    }

    kthSmallest(node->right, k, smallest);
}

int kthSmallestNumberInBSTRecursive(TreeNode* root, int k) {
    int smallest = root->val;
    kthSmallest(root, k, smallest);
    return smallest;
}
