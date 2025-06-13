#include <bits/stdc++.h>
using namespace std;

// Algorithm: Pre-Order Traversal

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        unordered_map<int, int> map;
        for (int i = 0; i < n; i++) {
            map[inorder[i]] = i;
        }

        return dfs(preorder, 0, inorder, 0, n - 1, map);
    }

private:
    TreeNode* dfs(vector<int>& preorder, int i, vector<int>& inorder, int j, int k, unordered_map<int, int>& map) {
        if (j > k) {
            return nullptr;
        }
        
        int val = preorder[i];
        TreeNode* node = new TreeNode(val);

        node->left = dfs(preorder, i + 1, inorder, j, map[val] - 1, map);
        node->right = dfs(preorder, i + (map[val] - j) + 1, inorder, map[val] + 1, k, map);

        return node;
    }
};
