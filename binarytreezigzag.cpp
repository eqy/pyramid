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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<TreeNode*> frontier = {root};
        bool lefttoright = true;
        int len = frontier.size();
        std::vector<std::vector<int>> levels;
        while (len) {
            std::vector<TreeNode*> new_frontier;
            std::vector<int> cur_level;
            for (auto it = frontier.begin(); it != frontier.end(); it++) {
                if (*it) {
                    cur_level.push_back((*it)->val);
                    if ((*it)->left) {
                        new_frontier.push_back((*it)->left);
                    }
                    if ((*it)->right) {
                        new_frontier.push_back((*it)->right);
                    }
                }
            }
            if (!lefttoright) {
                std::reverse(cur_level.begin(), cur_level.end());
            }
            if (cur_level.size()) {
                levels.push_back(cur_level);
            }
            lefttoright = !lefttoright;
            frontier = new_frontier;
            len = frontier.size();
        } 
        return levels;
    }
};
