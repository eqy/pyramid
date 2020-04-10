#include <iostream>
using namespace std;
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode * head = NULL;
        ListNode * cur = NULL; 
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int l1val = 0;
            int l2val = 0;
            if (l1 != NULL) {
                l1val = l1->val;
            }
            if (l2 != NULL) {
                l2val = l2->val;
            }
            int new_val = l1val + l2val + carry;
            if (new_val > 9) {
                carry = new_val / 10;
                new_val = new_val % 10;
            } else {
                carry = 0;
            }
            ListNode *new_digit = new ListNode(new_val);
            if (head == NULL) {
                head = new_digit;
            }
            if (cur != NULL) {
                cur->next = new_digit;
            }
            cur = new_digit;
            if (l1 != NULL) {
                l1 = l1->next;
            } 
            if (l2 != NULL) {
                l2 = l2->next;
            }
        }
        return head;
    }
};

int main(void) {
    struct ListNode a1(9);
    struct ListNode a2(9);
    struct ListNode a3(9);
    a2.next = &a3;
    a1.next = &a2;

    struct ListNode b1(9);
    struct ListNode b2(9);
    struct ListNode b3(9);
    b2.next = &b3;
    b1.next = &b2; 

    struct ListNode c1(0);
   
    ListNode *res = Solution().addTwoNumbers(&a1, &b1);
    while (res != NULL) {
        std::cout << res->val << std::endl;
        ListNode *temp = res->next;
        delete(res);
        res = temp;
    }

    ListNode *res2 = Solution().addTwoNumbers(&c1, &b1);
    while (res2 != NULL) {
        std::cout << res2->val << std::endl;
        ListNode *temp = res2->next;
        delete(res2);
        res2 = temp;
    }

}
