#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *curr = head;
        ListNode *prev = NULL;
        while (curr) {
            ListNode *right = curr->next;
            if (right) {
                ListNode *left = curr;
                ListNode *saved = right->next;
                if (prev) {
                    prev->next = right;
                } else {
                    head = right;
                }
                right->next = left;
                left->next = saved;
                prev = left;
                curr = saved;
            } else {
                curr = NULL;
            }
        }
        return head;
    }
};

int main(void) {
    ListNode a1(1);
    ListNode a2(2);
    ListNode a3(3);
    ListNode a4(4);
    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;
    ListNode *curr = Solution().swapPairs(&a1);
    while (curr) {
        std::cout << curr->val << std::endl;
        curr = curr->next;
    } 
    return 0;
}
