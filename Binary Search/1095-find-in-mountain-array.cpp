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
        int peak = 0;

        int l = 0;
        int r = mountainArr.length() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            int i = mountainArr.get(l);
            int j = mountainArr.get(mid);
            int k = mountainArr.get(r);

            // if () {

            // }
        }



    }
};
