#include <iostream>



/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       const int n_const = n+1;
       ListNode** window = new ListNode*[n_const];
       ListNode* cur = head;
       int count = 0;
       while (cur) {
           count += 1;
           for (int i = 0; i < n_const - 1; i++) {
               window[i] = window[i + 1];
           }
           window[n_const-1] = cur;
           cur= cur->next;
       } 
       if (count == n) {
           return head->next;
       }
       window[0]->next = window[1]->next;
       delete [] window;
       return head;
    }
};

int main(void) {
    ListNode a5 = ListNode(5);
    ListNode a4 = ListNode(4);
    ListNode a3 = ListNode(3);
    ListNode a2 = ListNode(2);
    ListNode a1 = ListNode(1);

    ListNode b2 = ListNode(2);
    ListNode b1 = ListNode(1);
    b1.next = &b2;

    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;
    a4.next = &a5;

    ListNode *temp = &a1;
    while (temp != NULL) {
        std::cout << temp->val << std::endl;
        temp = temp->next;
    }
    
    temp = Solution().removeNthFromEnd(&a1, 2);
    while (temp != NULL) {
        std::cout << temp->val << std::endl;
        temp = temp->next;
    }

    temp = Solution().removeNthFromEnd(&a5, 1);
    std::cout << temp << std::endl;
    while (temp != NULL) {
        std::cout << temp->val << std::endl;
        temp = temp->next;
    }

    temp = Solution().removeNthFromEnd(&b1, 2);
    while (temp != NULL) {
        std::cout << temp->val << std::endl;
        temp = temp->next;
    }

    return 0;
}
