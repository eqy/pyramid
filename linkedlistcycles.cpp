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
    bool hasCycle(ListNode *head) {
        std::set<ListNode *> visited;
        while (head != NULL) {
            if (visited.find(head) != visited.end()) {
                return true;
            }
            visited.insert(head);
            head = head->next;
        }
        return false;
    }
};
