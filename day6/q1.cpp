#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderHelper(root, result);
        return result;
    }
    
private:
    void inorderHelper(TreeNode* node, vector<int>& result) {
        if (!node) return;
        inorderHelper(node->left, result);  // Traverse left subtree
        result.push_back(node->val);       // Visit node
        inorderHelper(node->right, result); // Traverse right subtree
    }
};

int main() {
    // Example tree: [1, null, 2, 3]
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution solution;
    vector<int> result = solution.inorderTraversal(root);

    // Print the result
    cout << "Inorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Free the allocated memory
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
