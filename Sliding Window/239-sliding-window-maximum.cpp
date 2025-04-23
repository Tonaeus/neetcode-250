#include <bits/stdc++.h>
using namespace std;

// Data Structure: Monotonic Queue

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dmq;  

        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (!dmq.empty() && dmq.front() < l) {
                dmq.pop_front();
            }
            
            while (!dmq.empty() and nums[dmq.back()] < nums[r]) {
                dmq.pop_back();
            }
            dmq.push_back(r);

            if (r - l + 1 == k) {
                ans.push_back(nums[dmq.front()]);
                l++;
            }
        }  

        return ans;
    }
};
