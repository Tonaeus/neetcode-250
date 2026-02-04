#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n + (n - k)·log(n)) for KthLargest() and O(log(k)) for add()
// Space Complexity: O(k)

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : minHeap(nums.begin(), nums.end()) {
        this->k = k;
        
        while (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);

        if (minHeap.size() > k) {
            minHeap.pop();
        }

        return minHeap.top();
    }

private:
    int k;
    priority_queue<int, vector<int>, greater<>> minHeap;
};
