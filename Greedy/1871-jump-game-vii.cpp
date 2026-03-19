#include <bits/stdc++.h>
using namespace std;

// Algorithm: Breadth-First Search

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        
        queue<int> q;
        q.push(0);

        int farthest = 0;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            int l = max(i + minJump, farthest + 1);
            int r = min(i + maxJump + 1, n);

            for (int j = l; j < r; j++) {
                if (s[j] == '0') {
                    if (j == n - 1) {
                        return true;
                    }

                    q.push(j);
                }
            }

            farthest = r - 1;
        }

        return false;
    }
};
