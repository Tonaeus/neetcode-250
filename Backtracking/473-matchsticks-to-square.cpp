#include <bits/stdc++.h>
using namespace std;

// Technique: Pruning

// Time Complexity: O(2^n * k)
// Space Complexity: O(max(n, k))

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int k = 4;

        int perimeter = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        int length = perimeter / k;
        if (length * 4 != perimeter) {
            return false;
        }

        sort(matchsticks.rbegin(), matchsticks.rend());
        if (matchsticks.front() > length) {
            return false;
        }

        vector<int> sides(k);
        return dfs(matchsticks, 0, k, length, sides);
    }

private: 
    bool dfs(vector<int>& matchsticks, int i, int k, int length, vector<int>& sides) {
        if (i == matchsticks.size()) {
            return true;
        }

        for (int j = 0; j < k; j++) {
            if (sides[j] + matchsticks[i] > length) {
                continue;
            }

            sides[j] += matchsticks[i];
            if (dfs(matchsticks, i + 1, k, length, sides)) {
                return true;
            }
            sides[j] -= matchsticks[i];

             if (sides[j] == 0) {
                break;
             }
        }

        return false;
    }
};
