#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
// #include <unordered_map>  // can't compile on poj
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
private:
    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int in_l, int in_r, int& pre_i)
    {
        if (pre_i == preorder.size()) return nullptr;
        int now = preorder[pre_i++];
        int mid = in_l;
        for (; inorder[mid] != now && mid <= in_r; mid++);
        TreeNode *root = new TreeNode(now);
        if (mid > in_l) root->left = build(preorder, inorder, in_l, mid - 1, pre_i);
        if (mid < in_r) root->right = build(preorder, inorder, mid + 1, in_r, pre_i);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int pre_i = 0;
        return build(preorder, inorder, 0, inorder.size(), pre_i);
    }
};

int main()
{

    return 0;
}