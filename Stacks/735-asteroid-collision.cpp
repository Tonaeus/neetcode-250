#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;

        for (int a : asteroids) {
            if (stack.empty() or a > 0) {
                stack.push_back(a);
            }
            else {
                while (!stack.empty() and stack.back() > 0 and stack.back() < -a) {
                    stack.pop_back();
                }
                if (stack.empty() or stack.back() < 0) {
                    stack.push_back(a);
                }
                else if (stack.back() == -a) {
                    stack.pop_back();
                }
            }
        }

        return stack;
    }
};
