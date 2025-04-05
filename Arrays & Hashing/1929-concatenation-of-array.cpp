#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;
        ans.insert(ans.begin(), nums.begin(), nums.end());
        ans.insert(ans.begin() + nums.size(), nums.begin(), nums.end());

        return ans;
    }
};
