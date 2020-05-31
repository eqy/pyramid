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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        const int len = postorder.size();
        if (!len) {
            return NULL;
        } else {
            TreeNode* root;
            const int val = postorder[len - 1];
            root = new TreeNode(val);
            if (len > 1) {
                int count;
                for (count = 0; count < len; count++) {
                    if (inorder[count] == val) {
                        break;
                    }
                }
                int idx = count + 1 > len - 1 ? len - 1 : count + 1;
                int idx2 = count > len - 1 ? len - 1 : count;
                std::vector<int> leftinorder = std::vector<int>(inorder.begin(), inorder.begin() + count);
                std::vector<int> rightinorder = std::vector<int>(inorder.begin() + idx, inorder.end());
                std::vector<int> leftpostorder = std::vector<int>(postorder.begin(), postorder.begin() + count);
                std::vector<int> rightpostorder = std::vector<int>(postorder.begin() + idx2, postorder.begin() + len - 1);
                root->left = buildTree(leftinorder, leftpostorder);
                root->right = buildTree(rightinorder, rightpostorder);
            }
            return root;
        }
    }
};
