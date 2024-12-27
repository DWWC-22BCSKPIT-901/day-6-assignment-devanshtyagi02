#include <iostream>
#include <vector>
#include <stack>
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

// Iterative function to perform preorder traversal.
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    if (!root) return result;

    stack<TreeNode*> s;
    s.push(root);

    while (!s.empty()) {
        TreeNode* node = s.top();
        s.pop();

        result.push_back(node->val); // Visit the current node.

        // Push right child first so the left child is processed first.
        if (node->right) s.push(node->right);
        if (node->left) s.push(node->left);
    }

    return result;
}

int main() {
    // Example usage
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> result = preorderTraversal(root);
    cout << "Preorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl; // Output: 1 2 3

    return 0;
}
