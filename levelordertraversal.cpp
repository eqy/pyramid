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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<TreeNode *> frontier  = {root};
        std::vector<std::vector<int>> res;
        while (frontier.size()) {
            std::vector<TreeNode *> new_frontier;
            std::vector<int> cur;
            for (auto it = frontier.begin(); it != frontier.end(); it++) {
                if (*it) {
                    cur.push_back((*it)->val);
                    if ((*it)->left) {
                        new_frontier.push_back((*it)->left);
                    }
                    if ((*it)->right) {
                        new_frontier.push_back((*it)->right);
                    }
                }
            }
            frontier = new_frontier;
            if (cur.size()) {
                res.push_back(cur); 
            }

        }
        return res;
    }
};
