#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(1) for set() and O(log(n)) for get()
// Space Complexity: O(m * n)

class TimeMap {
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        map[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        int l = 0;
        int r = map[key].size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int t = map[key][mid].first;
            
            if (t < timestamp) {
                l = mid + 1;
            }
            else if (t > timestamp) {
                r = mid - 1;
            }
            else {
                return map[key][mid].second;
            }
        }

        return r < 0 ? "" : map[key][r].second;
    }

private: 
    unordered_map<string, vector<pair<int, string>>> map;
};
