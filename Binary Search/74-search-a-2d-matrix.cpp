#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(log(m * n))
// Space Complexity: O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int l = 0;
        int r = m * n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int i = mid / n;
            int j = mid % n;
            if (matrix[i][j] < target) {
                l = mid + 1;
            }
            else if (matrix[i][j] > target) {
                r = mid - 1;
            }
            else {
                return true;
            }
        }

        return false;
    }
};
    