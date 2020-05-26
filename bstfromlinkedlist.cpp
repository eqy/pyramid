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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(std::vector<int> &arr) {
        const int len = arr.size();
        if (!len) {
            return NULL;
        } else if (len == 1) {
            return new TreeNode(arr[0], NULL, NULL);
        } else {
            const int median = len/2;
            std::vector<int> leftarr(arr.begin(), arr.begin() + median);
            std::vector<int> rightarr(arr.begin() + median + 1, arr.end());
            TreeNode* left = sortedArrayToBST(leftarr);
            TreeNode* right = sortedArrayToBST(rightarr);
            return new TreeNode(arr[median], left, right);
        }
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        std::vector<int> arr;
        while (head != NULL) {
            arr.push_back(head->val);
            head = head->next;
        }
        return sortedArrayToBST(arr);
    }
};
