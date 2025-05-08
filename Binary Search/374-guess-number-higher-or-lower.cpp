#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(log(n))
// Space Complexity: O(1)

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 1;
        int r = n;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int g = guess(mid);
            if (g == 1) {
                l = mid + 1;
            }
            else if (g == -1) {
                r = mid - 1;
            }
            else {
                return mid;
            }
        }

        return 0;
    }
};
