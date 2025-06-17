#include <bits/stdc++.h>
using namespace std;

// Algorithm: Post-Order Traversal

// Time Complexity: O(n)
// Space Complexity: O(n)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return postorder(root, nullptr, target);
    }

private:
    TreeNode* postorder(TreeNode* node, TreeNode* parent, int target) {
        if (!node) {
            return nullptr;
        }

        node->left = postorder(node->left, node, target);
        node->right = postorder(node->right, node, target);

        if (!node->left and !node->right and node->val == target) {
            if (parent) {
                delete node;
            }
            return nullptr;
        }

        return node;
    }
};
