#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n·log(k))
// Space Complexity: O(k)

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](auto& a, auto& b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);

        for (auto list : lists) {
            if (list) {
                minHeap.push(list);
            }
        }

        ListNode dummy; 
        ListNode* curr = &dummy;
        ListNode* next = nullptr;

        while (!minHeap.empty()) {
            next = minHeap.top();
            minHeap.pop();

            curr->next = next;
            curr = curr->next;

            if (curr->next) {
                minHeap.push(curr->next);
            }
        }

        return dummy.next;
    }
};
