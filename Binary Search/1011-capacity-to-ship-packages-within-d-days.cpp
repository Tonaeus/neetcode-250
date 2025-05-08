#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n·log(s - m)) -> n = size of weights, m = max element of weights, s = total sum of weights
// Space Complexity: O(1)

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (helper(weights, mid) <= days) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }

        return l;
    }

private:
    int helper(vector<int>& weights, int capacity) {
        int res = 1;

        int sum = 0;
        for (int w : weights) {
            if (sum + w <= capacity) {
                sum += w;
            }
            else {
                sum = w;
                res += 1;
            }
        }

        return res;
    }
};
