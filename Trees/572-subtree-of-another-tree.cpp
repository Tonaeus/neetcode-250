#include <bits/stdc++.h>
using namespace std;

// Algorithm: Pre-Order Traversal

// Time Complexity: O(m * n) -> m = number of nodes in root, n = number of nodes in subRoot
// Space Complexity: O(m)

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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            return false;
        }

        if (isSameTree(root, subRoot)) {
            return true;
        }
        
        bool l = isSubtree(root->left, subRoot);
        bool r = isSubtree(root->right, subRoot);

        return l or r;
    }

private:
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
