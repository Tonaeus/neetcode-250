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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        postorder(root, ans);
        return ans;
    }

private:
    int postorder(TreeNode* node, int& ans) {
        if (!node) {
            return 0;
        }

        int l = max(0, postorder(node->left, ans));
        int r = max(0, postorder(node->right, ans));

        ans = max(ans, node->val + l + r);
        return node->val + max(l, r);
    }
};
