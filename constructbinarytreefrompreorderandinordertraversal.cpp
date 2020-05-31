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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        const int size = preorder.size();
        if (!size) {
            return NULL;
        }
        const int val = preorder[0];
        TreeNode* root = new TreeNode(val);
        if (size > 1) {
            int count;
            for (count = 0; count < size; count++) {
                if (inorder[count] == val) {
                    break;
                }
            }
            int idx = count + 1 >= size ? size : count + 1;
            int idx2 = count >= size ? size : count;
            std::vector<int> preorder_left = std::vector<int>(preorder.begin() + 1, preorder.begin() + idx);
            std::vector<int> preorder_right = std::vector<int>(preorder.begin() + idx, preorder.end());
            std::vector<int> inorder_left = std::vector<int>(inorder.begin(), inorder.begin() + idx2);
            std::vector<int> inorder_right = std::vector<int>(inorder.begin() + idx, inorder.end());
            root->left = buildTree(preorder_left, inorder_left);
            root->right = buildTree(preorder_right, inorder_right);
        }
        return root;
    }
};
