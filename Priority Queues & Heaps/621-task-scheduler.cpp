#include <bits/stdc++.h>
using namespace std;

// Technique: Mathematics

// Time Complexity: O(m)
// Space Complexity: O(1)

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m = tasks.size();

        vector<int> freq(26);
        for (char c : tasks) {
            freq[c - 'A']++;
        }

        int maxf = *max_element(freq.begin(), freq.end());
        int maxCnt = 0;
        for (int f : freq) {
            maxCnt += f == maxf;
        }

        return max(m, (n + 1) * (maxf - 1) + maxCnt);
    }
};
