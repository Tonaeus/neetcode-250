#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n·log(m)) -> n = size of piles, m = max element of piles
// Space Complexity: O(1)

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (helper(piles, mid) <= h) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }

        return l;
    }

private: 
    int helper(vector<int>& piles, int k) {
        int res = 0;

        for (int p : piles) {
            res += ceil(static_cast<double>(p) / k);
        }

        return res;
    }
};
