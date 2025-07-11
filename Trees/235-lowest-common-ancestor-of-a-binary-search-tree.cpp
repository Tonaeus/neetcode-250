#include <bits/stdc++.h>
using namespace std;

// Data Structure: Binary Search Tree

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return nullptr;
        }

        if (max(p->val, q->val) < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        if (min(p->val, q->val) > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }

        return root; 
    }
};
