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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p and !q) {
            return true; 
        }
        if (!p ^ !q) {
            return false; 
        }
        
        bool l = isSameTree(p->left, q->left);
        bool r = isSameTree(p->right, q->right);

        return l and r and p->val == q->val;
    }
};
