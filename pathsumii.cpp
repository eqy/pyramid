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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        std::vector<std::vector<int>> res;
        if (!root) {
            return res;
        } else if (!root->left && !root->right) {
            if (root->val == sum) {
                res.push_back({root->val});
            }
            return res;
        } else {
            const int curval = root->val;
            const int newsum = sum - curval;
            std::vector<std::vector<int>> temp_res_left = pathSum(root->left, newsum);
            std::vector<std::vector<int>> temp_res_right = pathSum(root->right, newsum);
            for (auto it = temp_res_left.begin(); it != temp_res_left.end(); it++) {
                it->insert(it->begin(), curval);
                res.push_back(*it);
            }
            for (auto it = temp_res_right.begin(); it != temp_res_right.end(); it++) {
                it->insert(it->begin(), curval);
                res.push_back(*it);
            }
            return res;
        }
    }
};
