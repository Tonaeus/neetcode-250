#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(log(n))
// Space Complexity: O(1)

class MountainArray {
public:
    int get(int index);
    int length();
};

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int peak = 0;

        int l = 1;
        int r = n - 2;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            int prevVal = mountainArr.get(mid - 1);
            int currVal = mountainArr.get(mid);
            int nextVal = mountainArr.get(mid + 1);

            if (prevVal > currVal) {
                r = mid - 1;
            }
            else if (nextVal > currVal) {
                l = mid + 1;
            }
            else {
                peak = mid;
                break;
            }
        }

        l = 0;
        r = peak - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int val = mountainArr.get(mid);
            if (val < target) {
                l = mid + 1;
            }
            else if (val > target) {
                r = mid - 1;
            }
            else {
                return mid;
            }
        }

        l = peak;
        r = n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int val = mountainArr.get(mid);
            if (val < target) {
                r = mid - 1;
            }
            else if (val > target) {
                l = mid + 1;
            }
            else {
                return mid;
            }
        }

        return -1;
    }
};
