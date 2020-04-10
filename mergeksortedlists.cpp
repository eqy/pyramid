#include <iostream>
#include <vector>
#include <algorithm>

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
    static bool cmp(ListNode *a, ListNode *b) {
        if (a && b) {
            return a->val > b->val;
        }
        return (bool) b;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::make_heap(lists.begin(), lists.end(), cmp);
        ListNode* head = NULL;
        ListNode* cur = NULL;
        while (lists.size() > 0) {
            ListNode* cur_min = lists.front();
            std::pop_heap(lists.begin(), lists.end(), cmp);
            lists.pop_back();
            if (!cur_min) {
                continue;
            }
            if (!head) {
                head = cur_min;
            }
            if (!cur) {
                cur = cur_min;
            } else {
                cur->next = cur_min;
                cur = cur->next;
            }
            ListNode* next = cur_min->next;
            if (next) {
                lists.push_back(next);
                std::push_heap(lists.begin(), lists.end(), cmp);
            }
        }
        if (cur) {
            cur->next = NULL;
        }
        return head;
    }
};

int main(void) {
    ListNode a3(5);
    ListNode a2(4);
    ListNode a1(1);
    a1.next = &a2;
    a2.next = &a3;

    ListNode b3(4);
    ListNode b2(3);
    ListNode b1(1);
    b1.next = &b2;
    b2.next = &b3;

    ListNode c2(6);
    ListNode c1(2);
    c1.next = &c2;
    
    std::vector<ListNode*> lists({&a1, &b1, &c1});
    ListNode * cur = Solution().mergeKLists(lists);
    while (cur) {
        std::cout << cur->val << std::endl;
        cur = cur->next;
    }
}
