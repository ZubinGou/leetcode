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

// If a node has only one child, that child is guaranteed to be the left child.

class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        int level, val;
        vector<TreeNode*> st;
        for (int i = 0; i < traversal.length();) {
            // get level
            for (level = 0; traversal[i] == '-'; i++)
                level++;
            // get val
            for (val = 0; i < traversal.length() && traversal[i] != '-'; i++)
                val = val * 10 + traversal[i] - '0';
            
            while (st.size() > level) st.pop_back();
            TreeNode* now = new TreeNode(val);
            if (st.size() != 0) {
                if (!st.back()->left) st.back()->left = now;
                else st.back()->right = now;
            }
            st.push_back(now);
        }
        return st[0];
    }
};