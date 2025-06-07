#include <bits/stdc++.h>
using namespace std;

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
    int goodNodes(TreeNode* root) {
        return preorder(root, root->val);
    }

private:
    int preorder(TreeNode* node, int maxVal) {
        if (!node) {
            return 0;
        }

        maxVal = max(maxVal, node->val);

        int l = preorder(node->left, maxVal);
        int r = preorder(node->right, maxVal);

        return l + r + (node->val >= maxVal);
    }
};
