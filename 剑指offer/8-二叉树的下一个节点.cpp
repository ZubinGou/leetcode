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
    TreeNode *father;
    TreeNode(int x) : val(x), left(NULL), right(NULL), father(NULL) {}
};

class Solution
{
public:
    TreeNode *inorderSuccessor(TreeNode *p)
    {
        // nullpre
        if (!p) return p;
        // root
        if (!p->father) return p->right;

        TreeNode *res = nullptr;
        // has right son
        if (p->right)
        {
            res = p->right;
            while (res->left)
                res = res->left;
        }
        // no right son
        else
        {
            if (p->father->left == p) // p is left son
            {
                // left son -> father
                res = p->father;
            }
            else // p is right son
            {
                // back to root till has right son
                res = p;
                while (res && res->father && res->father->right == res)
                    res = res->father;
                res = res->father;
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}