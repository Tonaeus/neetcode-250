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
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> dp;
        return dfs(root, dp);
    }

private:
    int dfs(TreeNode* node, unordered_map<TreeNode*, int>& dp) {
        if (!node) {
            return 0;
        }

        if (dp.contains(node)) {
            return dp[node];
        }

        int include = node->val; 
        if (node->left) {
            include += dfs(node->left->left, dp);
            include += dfs(node->left->right, dp);
        }
        if (node->right) {
            include += dfs(node->right->left, dp);
            include += dfs(node->right->right, dp);
        }

        int exclude = dfs(node->left, dp) + dfs(node->right, dp);

        return dp[node] = max(include, exclude);
    }
};
