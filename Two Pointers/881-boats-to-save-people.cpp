#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n·log(n))
// Space Complexity: O(log(n))

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0;
        int l = 0;
        int r = people.size() - 1;

        sort(people.begin(), people.end());

        while (l <= r) {
            if (l != r and people[l] + people[r] <= limit) {
                ans++;
                l++;
                r--;
            }
            else {
                ans++;
                r--;
            }
        }

        return ans;
    }
};
