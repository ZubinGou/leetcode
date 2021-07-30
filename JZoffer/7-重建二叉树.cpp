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

/*
因为每个结点的数不同，所以可以提前用 hash map 存储每个数在 inorder 数组中的位置，每次寻找当前根结点位置复杂度为 O(1)
*/

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