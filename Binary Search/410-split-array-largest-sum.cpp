#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n·log(s)) -> n = size of nums, s = total sum of nums
// Space Complexity: O(1)

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (helper(nums, mid) <= k) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }

        return l;
    }

private:
    int helper(vector<int>& nums, int largestSum) {
        int currSum = 0;
        int k = 1;

        for (int n : nums) {
            currSum += n;
            if (currSum > largestSum) {
                currSum = n;
                k++;
            }
        }

        return k;
    }   
};
