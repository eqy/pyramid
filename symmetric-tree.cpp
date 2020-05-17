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
    bool isSymmetric(TreeNode* root) {
        std::vector<TreeNode *> frontier = {root};
        while (true) {
            std::vector<TreeNode *> new_frontier;
            for (auto it = frontier.begin(); it != frontier.end(); it++) {
                if (*it != NULL) {
                    new_frontier.push_back((*it)->left);
                    new_frontier.push_back((*it)->right);
                }
            }
            const int new_frontier_size = new_frontier.size();
            if (!new_frontier_size) {
                return true;
            } else {
                for (int i = 0; i < new_frontier_size/2; i++) {
                    if (!(new_frontier[i] || new_frontier[new_frontier_size-1-i])) {
                        continue;
                    }
                    if (!new_frontier[i] || !new_frontier[new_frontier_size-1-i]) {
                        return false;
                    }
                    if (new_frontier[i]->val != new_frontier[new_frontier_size-1-i]->val) {
                        return false;
                    }
                }
                frontier = new_frontier;
            }
        }
    }
};
