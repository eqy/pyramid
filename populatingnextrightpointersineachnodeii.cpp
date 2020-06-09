/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* right(Node* root, int levels) {
        if (!levels || !root) {
            return root;
        } else {
            Node* leftchoice = right(root->left, levels - 1);
            if (leftchoice) {
                return leftchoice;
            } else {
                return right(root->right, levels - 1);
            }
        }   
    }
    
    Node* left(Node *root, int levels) {
        if (!levels || !root) {
            return root;
        } else {
            Node* rightchoice = left(root->right, levels - 1);
            if (rightchoice) {
                return rightchoice;
            } else {
                return left(root->left, levels - 1);
            }
        }
    }
    
    Node* connect(Node* root) {
        if (root) {
            connect(root->left);
            connect(root->right);
            int levels = 0;
            while (true) {
                Node *cur_left = root->left;
                Node *cur_right = root->right;
                cur_left = left(cur_left, levels);
                cur_right = right(cur_right, levels);
                if (cur_left && cur_right) {
                    cur_left->next = cur_right; 
                } else {
                    break;
                }
                levels++;
            }
        }
        return root;
    }
};
