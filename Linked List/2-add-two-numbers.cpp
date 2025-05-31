#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(max(m, n))
// Space Complexity: O(max(m, n))

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;

        ListNode* curr1 = l1;
        ListNode* curr2 = l2; 

        int carry = 0;
        while (curr1 or curr2 or carry) {
            int addend1 = curr1 ? curr1->val : 0;
            int addend2 = curr2 ? curr2->val : 0;

            int sum = addend1 + addend2 + carry; 
            int lsd = sum % 10;
            carry = sum / 10;

            curr->next = new ListNode(lsd);
            
            curr1 = curr1 ? curr1->next : nullptr;
            curr2 = curr2 ? curr2->next : nullptr;

            curr = curr->next;
        }

        return dummy.next;
    }
};
