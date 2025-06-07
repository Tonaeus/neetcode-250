#include <bits/stdc++.h>
using namespace std;

// Algorithm: Breadth-First Search

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            vector<int> level; 

            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node) {
                    q.push(node->left);
                    q.push(node->right);
                    level.push_back(node->val);
                }
            }

            if (!level.empty()) {
                ans.push_back(level);
            }
        }

        return ans;
    }
};
