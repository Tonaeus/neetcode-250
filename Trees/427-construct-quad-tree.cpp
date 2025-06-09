#include <bits/stdc++.h>
using namespace std;

// Data Structure: Quadtree 

// Time Complexity: O(n^2)
// Space Complexity: O(log(n))

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return dfs(grid, 0, 0, grid.size());
    }

private: 
    Node* dfs(vector<vector<int>>& grid, int r, int c, int n) {
        if (n == 1) {
            return new Node(grid[r][c], true);
        }

        int half = n / 2;
        Node* topLeft = dfs(grid, r, c, half);
        Node* topRight = dfs(grid, r, c + half, half);
        Node* bottomLeft = dfs(grid, r + half, c, half);
        Node* bottomRight = dfs(grid, r + half, c + half, half); 

        if (topLeft->isLeaf &&
            topRight->isLeaf &&
            bottomLeft->isLeaf &&
            bottomRight->isLeaf &&
            topLeft->val == topRight->val && 
            topLeft->val == bottomLeft->val &&
            bottomLeft->val == bottomRight->val
        ) {
            return new Node(grid[r][c], true); 
        }

        return new Node(grid[r][c], false, topLeft, topRight, bottomLeft, bottomRight);
    }
};
