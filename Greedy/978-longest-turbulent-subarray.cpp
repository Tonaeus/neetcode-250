#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int ans = 1;
        int d = 1;
        int u = 1;

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < arr[i - 1]) {
                d = u + 1;
                u = 1;
            }
            else if (arr[i] > arr[i - 1]) {
                u = d + 1;
                d = 1;
            }
            else {
                d = 1;
                u = 1;
            }

            ans = max({ans, d, u});
        }

        return ans;
    }
};
