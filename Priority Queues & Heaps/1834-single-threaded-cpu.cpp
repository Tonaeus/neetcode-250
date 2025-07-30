#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n·log(n))
// Space Complexity: O(n)

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        auto cmp1 = [](const auto& a, const auto& b) {
            return a[0] > b[0];
        };
        priority_queue<array<int, 3>, vector<array<int, 3>>, decltype(cmp1)> minHeap1(cmp1);
        
        auto cmp2 = [](const auto& a, const auto& b) {
            return a[1] == b[1] ? a[2] > b[2] : a[1] > b[1];
        };
        priority_queue<array<int, 3>, vector<array<int, 3>>, decltype(cmp2)> minHeap2(cmp2);
    
        long long time = 0;
        vector<int> ans;

        for (int i = 0; i < tasks.size(); i++) {
            minHeap1.push({tasks[i][0], tasks[i][1], i});
        }

        while (!minHeap1.empty() or !minHeap2.empty()) {
            while (!minHeap1.empty() and minHeap1.top()[0] <= time) {
                minHeap2.push(minHeap1.top());
                minHeap1.pop();
            }

            if (!minHeap2.empty()) {
                auto task = minHeap2.top();
                minHeap2.pop();
    
                time += task[1];
                ans.push_back(task[2]);
            }
            else if (!minHeap1.empty()) {
                time = minHeap1.top()[0];
            }
        }

        return ans;
    }
};
