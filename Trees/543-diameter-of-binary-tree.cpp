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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        postorder(root, ans);
        return ans;
    }

private:
    int postorder(TreeNode* node, int& ans) {
        if (!node) {
            return 0;
        }

        int l = postorder(node->left, ans);
        int r = postorder(node->right, ans);
        ans = max(ans, l + r);

        return max(l, r) + 1;
    }
};
