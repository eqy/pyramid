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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        std::vector<TreeNode*> frontier;
        if (root) {
            frontier.push_back(root);
        }
        std::vector<std::vector<int>> levels;
        while (frontier.size()) {
            std::vector<int> cur_level;
            std::vector<TreeNode*> new_frontier;
            for (auto it = frontier.begin(); it != frontier.end(); it++) {
                if ((*it)->left) {
                    new_frontier.push_back((*it)->left);
                }
                if ((*it)->right) {
                    new_frontier.push_back((*it)->right);
                }
                cur_level.push_back((*it)->val);
            }
            frontier = new_frontier;
            levels.insert(levels.begin(), cur_level);
        }
        return levels;
    }
};
