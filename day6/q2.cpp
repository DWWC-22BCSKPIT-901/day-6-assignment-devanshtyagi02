#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Function to calculate the depth of the tree.
int getDepth(TreeNode* node) {
    int depth = 0;
    while (node) {
        depth++;
        node = node->left;
    }
    return depth;
}

int countNodes(TreeNode* root) {
    if (!root) return 0;

    int leftDepth = getDepth(root->left);
    int rightDepth = getDepth(root->right);

    if (leftDepth == rightDepth) {
        // Left subtree is a perfect binary tree.
        return (1 << leftDepth) + countNodes(root->right);
    } else {
        // Right subtree is a perfect binary tree.
        return (1 << rightDepth) + countNodes(root->left);
    }
}

int main() {
    // Example usage
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    cout << "Number of nodes: " << countNodes(root) << endl;
    return 0;
}
