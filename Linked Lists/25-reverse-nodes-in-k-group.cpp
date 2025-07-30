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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* bl = &dummy;

        while (getKGroupEnd(bl, k)) {
            ListNode* l = bl->next;
            ListNode* curr = nullptr;
            
            for (int i = 0; i < k - 1; i++) {
                curr = l->next;
                l->next = curr->next; 
                curr->next = bl->next;
                bl->next = curr;
            }

            bl = l;
        }

        return dummy.next;
    }

private: 
    ListNode* getKGroupEnd(ListNode* head, int k) {
        while (head && k > 0) {
            head = head->next;
            k--;
        }
        return head;
    }
};
