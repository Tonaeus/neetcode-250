#include <bits/stdc++.h>
using namespace std;

// Data Structure: Ordered Map

// Time Complexity: O(n·log(n))
// Space Complexity: O(n)

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> map; 

        for (int card : hand) {
            map[card]++;
        }

        while (!map.empty()) {
            auto start = map.begin()->first;

            for (int i = start; i < start + groupSize; i++) {
                if (!map.contains(i)) {
                    return false;
                }

                map[i]--;
                if (map[i] == 0) {
                    map.erase(i);
                }
            }
        }

        return true;
    }
};
