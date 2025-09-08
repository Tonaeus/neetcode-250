#include <bits/stdc++.h>
using namespace std;

// Algorithm: Graph Traversal (Depth-First Search)

// Time Complexity: O(v + e)
// Space Complexity: O(v)

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }

        unordered_map<Node*, Node*> map;
        return dfs(node, map);
    }

private:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& map) {
        if (map.contains(node)) {
            return map[node];
        }

        Node* copy = new Node(node->val);
        map[node] = copy;

        for (const auto& nbr : node->neighbors) {
            copy->neighbors.push_back(dfs(nbr, map));
        }

        return copy;
    }
};
