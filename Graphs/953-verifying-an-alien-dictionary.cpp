#include <bits/stdc++.h>
using namespace std;

// Data Structure: Rank Map

// Time Complexity: O(n * k), n = number of words, k = average word length
// Space Complexity: O(1)

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> map(26);

        for (int i = 0; i < 26; i++) {
            map[order[i] - 'a'] = i;
        }
        
        for (int i = 1; i < words.size(); i++) {
            string& w1 = words[i - 1];
            string& w2 = words[i];

            for (int j = 0; j < w1.length(); j++) {
                if (j == w2.length()) {
                    return false;
                }
                if (w1[j] != w2[j]) {
                    if (map[w1[j] - 'a'] > map[w2[j] - 'a']) {
                        return false;
                    }
                    break;
                }
            }
        }

        return true;
    }
};
