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

// Function to find the maximum depth of the binary tree.
int maxDepth(TreeNode* root) {
    if (!root) return 0; // Base case: if the tree is empty, depth is 0.

    // Recursively find the depth of the left and right subtrees.
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    // Return the maximum depth between the two subtrees plus 1 (for the current node).
    return max(leftDepth, rightDepth) + 1;
}

int main() {
    // Example usage
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "Maximum Depth: " << maxDepth(root) << endl; // Output: 3
    return 0;
}
