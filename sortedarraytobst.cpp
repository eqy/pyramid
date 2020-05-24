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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        const int len = nums.size();

        if (!len) {
            return NULL;
        } else if (len == 1) {
            return new TreeNode(nums[0]);
        } else {
            int median_idx = len/2;
            std::vector<int> leftvec = std::vector<int>(nums.begin(), nums.begin()+median_idx);
            std::vector<int> rightvec = std::vector<int>(nums.begin()+median_idx+1, nums.end());
            TreeNode *left = sortedArrayToBST(leftvec); 
            TreeNode *right = sortedArrayToBST(rightvec);
            return new TreeNode(nums[median_idx], left, right);
        }
    }
};
