#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(k)

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto dist = [](const auto& p) { 
            return (p[0] * p[0]) + (p[1] * p[1]);
        };
        auto comp = [&](const auto& a, const auto& b) { 
            return dist(a) < dist(b);
        };
        
        nth_element(points.begin(), points.begin() + k - 1, points.end(), comp);

        return vector(points.begin(), points.begin() + k);
    }
};
