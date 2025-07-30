#include <bits/stdc++.h>
using namespace std;

// Algorithm: Sweep Line

// Time Complexity: O(n + d) -> n = size of trips, d = difference between the rightmost location and leftmost location
// Space Complexity: O(d)

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int l = INT_MAX;
        int r = INT_MIN;
        for (auto& t : trips) {
            l = min(l, t[1]);
            r = max(r, t[2]);
        }

        int d = r - l + 1;
        vector<int> changes(d + 1);
        for (auto& t : trips) {
            changes[t[1] - l] += t[0];
            changes[t[2] - l] -= t[0];
        }

        int passengers = 0;
        for (int c : changes) {
            passengers += c;
            if (passengers > capacity) {
                return false;
            }
        }

        return true;
    }
};
