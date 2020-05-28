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
    void flatten(TreeNode* root) {
        if (!root || !root->left && !root->right) {
            return;
        } else if (!root->left && !!root->right) {
            flatten(root->right);
        } else if (!!root->left && !root->right) {
            flatten(root->left);
            root->right = root->left;
            root->left = NULL;
        } else {
            flatten(root->left);
            flatten(root->right);
            TreeNode * left = root->left;
            TreeNode * right = root->right;
            root->right = left;
            root->left = NULL;
            TreeNode * cur = left;
            while (true) {
                if (!cur->right) {
                    cur->right = right;
                    break;
                }
                cur = cur->right;
            }
        }
    }
};
