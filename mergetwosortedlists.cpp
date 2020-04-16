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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       ListNode *head = NULL;
       ListNode *cur;
       while (l1 || l2) {
            if (l1 && l2) {
                if (l1->val < l2->val) {
                    if (head) {
                        cur->next = l1;
                        cur = l1;
                        l1 = l1->next;
                    } else {
                        cur = l1;
                        l1 = l1->next;
                        head = cur;
                    }
                } else {
                    if (head) {
                        cur->next = l2;
                        cur = l2;
                        l2 = l2->next;
                    } else {
                        cur = l2;
                        l2 = l2->next;
                        head = cur;
                    } 
                }
            } else if (l1) {
                if (head) {
                    cur->next = l1;
                } else {
                    cur = l1;
                    head = cur; 
                }
                break;
            } else {
                if (head) {
                    cur->next = l2;
                } else {
                    cur = l2;
                    head = cur;
                }
                break;
            }
       } 
       return head; 
    }
};

int main(void) {
    ListNode a3(4);
    ListNode a2(2);
    ListNode a1(1);
    ListNode b3(4);
    ListNode b2(3);
    ListNode b1(1);

    a1.next = &a2;
    a2.next = &a3;
    b1.next = &b2;
    b2.next = &b3;

    ListNode *temp = Solution().mergeTwoLists(NULL, &a3);
    while (temp) {
        std::cout << temp->val << std::endl;
        temp = temp->next;
    } 
    return 0;
}
