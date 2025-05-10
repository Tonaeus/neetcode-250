#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(log(n))
// Space Complexity: O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] <= nums[r]) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }

        int pivot = l;
        l = 0;
        r = n - 1;

        if (nums[pivot] <= target and target <= nums[r]) {
            l = pivot;
        }
        else {
            r = pivot - 1;
        }

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            }
            else if (nums[mid] > target) {
                r = mid - 1;
            }
            else {
                return mid;
            }
        }

        return -1;
    }
};
