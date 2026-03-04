#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveCount = 0;
        int tenCount = 0;

        for (int b : bills) {
            if (b == 5) {
                fiveCount++;
            }
            else if (b == 10) {
                tenCount++;
                fiveCount--;
            }
            else if (b == 20) {
                if (tenCount > 0) {
                    tenCount--;
                    fiveCount--;
                }
                else {
                    fiveCount -= 3;
                }
            }

            if (fiveCount < 0) {
                return false;
            } 
        }

        return true;
    }
};
