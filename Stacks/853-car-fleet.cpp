#include <bits/stdc++.h>
using namespace std;

// Data Structure: Monotonic Stack

// Time Complexity: O(n·log(n))
// Space Complexity: O(n)

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> arr(n);

        for (int i = 0; i < n; i++) {
            double time = 1.0 * (target - position[i]) / speed[i];
            arr[i] = {position[i], time};
        }

        sort(arr.begin(), arr.end());

        stack<double> dms;
        for (int i = 0; i < n; i++) {
            while(!dms.empty() and dms.top() <= arr[i].second) {
                dms.pop();
            }
            dms.push(arr[i].second);
        }

        return dms.size();
    }
};
