#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n * k)
// Space Complexity: O(n * k)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for (string& str : strs) {
            vector<int> freq(26);
            for (char c : str) {
                freq[c - 'a']++;
            }

            string freqStr;
            for (int cnt : freq) {
                freqStr.push_back(cnt);
                freqStr.push_back('/'); 
            }

            map[freqStr].push_back(str); 
        }

        vector<vector<string>> ans;
        for (auto& [key, val] : map) {
            ans.push_back(val);
        }

        return ans;
    }
};
