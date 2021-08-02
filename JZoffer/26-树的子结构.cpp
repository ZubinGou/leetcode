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

// Definition for a binary tree node.
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
    bool isSame(TreeNode *rA, TreeNode *rB) {
        if (!rB) return true;
        if (!rA) return false;
        return rA->val == rB->val && isSame(rA->left, rB->left) && isSame(rA->right, rB->right);
    }

public:
    bool hasSubtree(TreeNode *rA, TreeNode *rB)
    {
        if (!rA || !rB) return false;
        return isSame(rA, rB) || hasSubtree(rA->left, rB) || hasSubtree(rA->right, rB);
    }
};

int main()
{

    return 0;
}