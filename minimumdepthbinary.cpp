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
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        } else {
            int lMin = minDepth(root->left);
            int rMin = minDepth(root->right);
            if (!rMin && !lMin) {
                return 1;
            } else if (!rMin) {
                return 1 + lMin;
            } else if (!lMin) {
                return 1 + rMin;
            }
            return 1 + (lMin > rMin ? rMin : lMin);
        }
    }
};
