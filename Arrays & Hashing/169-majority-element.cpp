#include <bits/stdc++.h>
using namespace std;

// Algorithm: Boyer-Moore Majority Vote

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0;
        int count = 0;

        for (int num : nums) {
            if (count == 0) {
                ans = num;
            }
            
            if (num == ans) {
                count++;
            } 
            else {
                count--;
            }
        }

        return ans;
    }
};
