#include <iostream>
#include <queue>
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

// Iterative function to find the sum of all nodes using a queue.
int sumOfNodes(TreeNode* root) {
    if (!root) return 0; // If the tree is empty, the sum is 0.

    int sum = 0;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        sum += current->val; // Add the value of the current node.

        // Add the left and right children to the queue if they exist.
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }

    return sum;
}

int main() {
    // Example usage
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(7);

    cout << "Sum of all nodes: " << sumOfNodes(root) << endl; // Output: 28
    return 0;
}
