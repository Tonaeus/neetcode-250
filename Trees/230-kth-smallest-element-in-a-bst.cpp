#include <bits/stdc++.h>
using namespace std;

// Algorithm: In-Order Traversal

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
    int kthSmallest(TreeNode* root, int k) {
        return inorder(root, k);
    }

private:
    int inorder(TreeNode* node, int& k) {
        if (!node) {
            return -1;
        }

        int l = inorder(node->left, k);

        k--;
        if (k == 0) {
            return node->val;
        }

        int r = inorder(node->right, k);

        return max(l, r);
    }
};
