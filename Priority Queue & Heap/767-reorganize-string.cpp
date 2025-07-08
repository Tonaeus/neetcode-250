#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26);
        for (char c : s) {
            freq[c - 'a']++;
        }

        priority_queue<pair<int, char>> maxHeap;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                maxHeap.push({freq[i], i + 'a'});
            }
        }
        
        string ans;

        pair<int, char> prev;
        while (!maxHeap.empty() or prev.first > 0) {
            if (maxHeap.empty() and prev.first > 0) {
                return "";
            }

            auto [f, c] = maxHeap.top();
            maxHeap.pop();

            ans += c;
            f--;

            if (prev.first > 0) {
                maxHeap.push(prev);
            }

            prev = {f, c};
        }

        return ans;
    }
};
