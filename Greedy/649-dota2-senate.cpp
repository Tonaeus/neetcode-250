#include <bits/stdc++.h>
using namespace std;

// Data Structure: Queue

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> rq, dq;

        for (int i = 0; i < n; i++) {
            senate[i] == 'R' ? rq.push(i) : dq.push(i);
        }

        while (!rq.empty() and !dq.empty()) {
            int ri = rq.front();
            rq.pop();
            
            int di = dq.front();
            dq.pop();

            if (ri < di) {
                rq.push(ri + n);
            }
            else {
                dq.push(di + n);
            }
        }

        return rq.empty() ? "Dire" : "Radiant";
    }
};
