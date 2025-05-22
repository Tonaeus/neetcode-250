#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(log(m + n))
// Space Complexity: O(1)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int total = m + n;
        int half = total / 2;
        
        int l = 0;
        int r = m;

        while (l <= r) {
            int mid1 = l + (r - l) / 2;
            int mid2 = half - mid1;

            int l1 = mid1 == 0 ? INT_MIN : nums1[mid1 - 1];
            int r1 = mid1 == m ? INT_MAX : nums1[mid1]; 
            int l2 = mid2 == 0 ? INT_MIN : nums2[mid2 - 1];
            int r2 = mid2 == n ? INT_MAX : nums2[mid2]; 

            if (l1 <= r2 and l2 <= r1) {
                if (total % 2 == 0) {
                    return (min(r1, r2) + max(l1, l2)) / 2.0;
                }
                else {
                    return min(r1, r2);
                }
            }
            else if (l2 > r1) {
                l = mid1 + 1;
            }
            else {
                r = mid1 - 1;
            }
        }

        return 0;
    }
};
