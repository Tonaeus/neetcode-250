#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int currentGas = 0;

        int start = 0;

        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i] - cost[i];
            currentGas += gas[i] - cost[i];

            if (currentGas < 0) {
                currentGas = 0;
                start = i + 1;
            }
        }

        return totalGas < 0 ? -1 : start;
    }
};
