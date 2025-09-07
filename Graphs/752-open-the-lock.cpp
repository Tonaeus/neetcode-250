#include <bits/stdc++.h>
using namespace std;

// Algorithm: Breadth-First Search

// Time Complexity: O(m + d^n)
// Space Complexity: O(d^n)

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited(deadends.begin(), deadends.end());
        if (visited.contains("0000")) {
            return -1;
        }

        int t = 0;

        queue<string> q;

        visited.insert("0000");
        q.push("0000");

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                string curr = q.front();
                q.pop();

                if (curr == target) {
                    return t;
                }

                for (int i = 0; i < 4; i++) {
                    for (int d : {-1, 1}) {
                        string next = curr;
                        next[i] = (next[i] - '0' + d + 10) % 10 + '0';

                        if (!visited.count(next)) {
                            visited.insert(next);
                            q.push(next);
                        }
                    }
                }
            }

            t++;
        }

        return -1;
    }
};
