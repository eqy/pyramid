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
    void _reverseKGroup(ListNode* &newhead, ListNode* head, int k, int start,
int len, ListNode* next) {
        int count = 0;
        ListNode* cur = head;
        while (count < start) {
            cur = cur->next;
            count++;
        }
        ListNode* prev = NULL;
        ListNode* first = cur;
        for (int i = 0; i < k; i++) {
            
            if (prev) {
                ListNode* temp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = temp;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        first->next = next;
        if (start == 0) {
            newhead = prev;
        } else if (start - k >= 0) {
            _reverseKGroup(newhead, head, k, start-k, len, prev);
        }
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = 0;
        ListNode * cur = head;
        while (cur != NULL) {
            len += 1;
            cur = cur->next;
        }
        if (k > len) {
            return head;
        } else {
            int start = (len - (len % k)) - k;
            cur = head;
            int count = 0;
            while (count < start + k) {
                cur = cur->next;
                count++;
            }
            _reverseKGroup(head, head, k, start, len, cur);
            return head;
        }
    }
};
