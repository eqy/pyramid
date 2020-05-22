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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) {
            return false;
        }
        if (!(root->left) && !(root->right)) {
            if (sum - root->val == 0) {
                return true;
            } else {
                return false;
            }
        } else {
            const int newSum = sum - root->val;
            bool res = false;
            if (root->left) {
                res |= hasPathSum(root->left, newSum);
            }
            if (root->right) {
                res |= hasPathSum(root->right, newSum);
            }
            return res;
        }
    }
};
