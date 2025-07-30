#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n·log(n))
// Space Complexity: O(n)

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        auto cmpCapital = [&](int a, int b) {
            return capital[a] > capital[b];
        };
        auto cmpProfit = [&](int a, int b) {
            return profits[a] < profits[b];
        };

        priority_queue<int, vector<int>, decltype(cmpCapital)> minCapital(cmpCapital);
        priority_queue<int, vector<int>, decltype(cmpProfit)> maxProfit(cmpProfit);

        for (int i = 0; i < profits.size(); i++) {
            minCapital.push(i);
        }

        int ans = w;

        for (int i = 0; i < k; i++) {
            while (!minCapital.empty() and capital[minCapital.top()] <= ans) {
                maxProfit.push(minCapital.top());
                minCapital.pop();
            }
            
            if (maxProfit.empty()) {
                break;
            }

            ans += profits[maxProfit.top()];
            maxProfit.pop();
        }

        return ans;
    }
};
