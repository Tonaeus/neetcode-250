#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0, head);
        ListNode* bl = &dummy; 

        for (int i = 0; i < left - 1; i++) {
            bl = bl->next; 
        }

        ListNode* l = bl->next;
        ListNode* curr = nullptr;

        for (int i = 0; i < right - left; i++) {
            curr = l->next;
            l->next = curr->next;
            curr->next = bl->next;
            bl->next = curr;
        }

        return dummy.next;
    }
};
