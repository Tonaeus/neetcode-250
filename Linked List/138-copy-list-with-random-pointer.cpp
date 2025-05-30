#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }

        Node* curr = head;
        while (curr) {
            Node* newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode; 
            curr = newNode->next;
        }

        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        Node* oldHead = head;
        Node* newHead = head->next;
        Node* oldCurr = oldHead;
        Node* newCurr = newHead;
        
        while (oldCurr) {
            oldCurr->next = newCurr->next;
            newCurr->next = newCurr->next ? newCurr->next->next : nullptr;
            oldCurr = oldCurr->next;
            newCurr = newCurr->next;
        }

        return newHead;
    }
};
