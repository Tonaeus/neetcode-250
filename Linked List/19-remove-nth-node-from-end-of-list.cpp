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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode* l = &dummy;
        ListNode* r = head;

        while (n > 0) {
            r = r->next;
            n--;
        }

        while (r) {
            l = l->next;
            r = r->next;
        }

        ListNode* temp = l->next;
        l->next = l->next->next;
        delete temp;

        return dummy.next;
    }
};
