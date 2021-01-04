/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int index = 0;
        ListNode sentinel(0, head);
        ListNode* leftend = &sentinel;
        ListNode* curr = &sentinel;
        while (index < m) {
            leftend = curr;
            curr = curr->next;
            index++;
        }
        ListNode* midhead = curr;
        ListNode* origmidhead = curr;
        curr = curr->next;
        while (curr && index < n) {
            ListNode* temp = curr->next;
            curr->next = midhead;
            midhead = curr;
            curr = temp;
            index++;
        }
        leftend->next = midhead;
        origmidhead->next = curr;
        ListNode* curr2 = midhead;
        return sentinel.next;
    }
};
