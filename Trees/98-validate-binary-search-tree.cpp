#include <bits/stdc++.h>
using namespace std;

// Time Complexity: 
// Space Complexity: 

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

    }

private:
    pair<int, int> postorder(TreeNode* node) {

    }
};
