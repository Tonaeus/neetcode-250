#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(1)
// Space Complexity: O(n)

class MinStack {
public:
    MinStack() {}
    
    void push(int val) {
        st.push(val);

        if (minSt.empty() or val <= minSt.top()) {
            minSt.push(val);
        }
    }
    
    void pop() {
        int val = st.top();
        st.pop();

        if (val == minSt.top()) {
            minSt.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }

private:
    stack<int> st;
    stack<int> minSt;
};
