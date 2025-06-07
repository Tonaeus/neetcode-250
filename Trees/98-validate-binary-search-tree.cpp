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
    bool isValidBST(TreeNode* root) {
        return postorder(root, LLONG_MIN, LLONG_MAX);
    }

private: 
    bool postorder(TreeNode* node, long long minVal, long long maxVal) {
        if (!node) {
            return true;
        }

        if (!(minVal < node->val and node->val < maxVal)) {
            return false;
        }

        bool l = postorder(node->left, minVal, node->val);
        bool r = postorder(node->right, node->val, maxVal);
        
        return l and r;
    }
};
