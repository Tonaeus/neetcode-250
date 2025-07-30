#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(a + b + c)
// Space Complexity: O(a + b + c)

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> maxHeap;
        if (a > 0) {
            maxHeap.push({a, 'a'});
        }
        if (b > 0) {
            maxHeap.push({b, 'b'});
        }
        if (c > 0) {
            maxHeap.push({c, 'c'});
        }
        
        string ans;

        while (!maxHeap.empty()) {
            auto [f, c] = maxHeap.top();
            maxHeap.pop();

            int n = ans.size();
            if (n >= 2 and ans[n - 1] == c and ans[n - 2] == c) {
                if (maxHeap.empty()) {
                    break;
                }

                auto [nf, nc] = maxHeap.top();
                maxHeap.pop();

                ans += nc;
                nf--;

                if (nf > 0) {
                    maxHeap.push({nf, nc});
                }
            }

            ans += c;
            f--;

            if (f > 0) {
                maxHeap.push({f, c});
            }
        }

        return ans;
    }
};
