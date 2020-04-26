#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
       if (!k or k < 0 or !head or !head->next) {
            return head;
       }
       ListNode *countcur = head;
       int count = 0;
       while (countcur != NULL) {
         count++;
         countcur = countcur->next;
       }
       k = k % count;
       for (int i = 0; i < k; i++) {
         ListNode *penult = NULL;
         ListNode *end = NULL;
         ListNode *cur = head;
         while (cur != NULL) {
           if (end) {
             penult = end;
           }
           end = cur;
           cur = cur->next;
         }
         end->next = head;
         penult->next = NULL;
         head = end;
       }
       return head;
    }
};

int main(void) {
    ListNode l5(5);
    ListNode l4(4);
    ListNode l3(3);
    ListNode l2(2);
    ListNode l1(1);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;

    ListNode b3(2);
    ListNode b2(1);
    ListNode b1(0);
    b1.next = &b2;
    b2.next = &b3;

    
    ListNode *cur = Solution().rotateRight(&l1, 2);
    while (cur != NULL) {
        std::cout << cur->val << std::endl;
        cur = cur->next;
    }
    cur = Solution().rotateRight(&b1, 4);
    while (cur != NULL) {
        std::cout << cur->val << std::endl;
        cur = cur->next;
    }

    return 0;
}
