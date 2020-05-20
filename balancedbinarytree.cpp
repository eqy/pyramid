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
    int height(TreeNode* root) {
        if (!root) {
            return 0;
        } else {
            const int lheight = height(root->left);
            const int rheight = height(root->right);
            return 1 + (lheight > rheight ? lheight : rheight);
        }
    }
    
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }
        int lheight = height(root->left);
        int rheight = height(root->right);
        int diff = lheight - rheight;
        if (diff < 0) {
            diff = -diff;
        }
        if (diff > 1) {
            return false;
        } else {
            return isBalanced(root->left) && isBalanced(root->right);
        }
    }
};
