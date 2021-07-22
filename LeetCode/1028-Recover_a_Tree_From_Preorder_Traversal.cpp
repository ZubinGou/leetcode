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
TreeNode* iter(string str, int depth, int& pos) {
    int val_begin = str.find_first_of("0123456789", pos);
    if (val_begin - pos != depth) return nullptr;
    pos = str.find('-', val_begin);
    int val = stoi(str.substr(val_begin, pos));
    
    TreeNode* root = new TreeNode(val);
    root->left = iter(str, depth + 1, pos);
    root->right = iter(str, depth + 1, pos);
    return root;
}

public:
    TreeNode* recoverFromPreorder(string traversal) {
        int pos = 0; 
        return iter(traversal, 0, pos);
    }
};