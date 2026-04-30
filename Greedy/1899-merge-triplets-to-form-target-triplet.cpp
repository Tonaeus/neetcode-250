#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool x = false;
        bool y = false;
        bool z = false;

        for (auto& t : triplets) {
            x |= t[0] == target[0] and t[1] <= target[1] and t[2] <= target[2];
            y |= t[0] <= target[0] and t[1] == target[1] and t[2] <= target[2];
            z |= t[0] <= target[0] and t[1] <= target[1] and t[2] == target[2];
        }

        return x and y and z;
    }
};
