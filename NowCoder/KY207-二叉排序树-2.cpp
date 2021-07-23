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
    TreeNode *leftChild;
    TreeNode *rightChild;
    TreeNode(int v) : val(v), leftChild(nullptr), rightChild(nullptr) {}
};

TreeNode *insert(TreeNode *root, int now, int father)
{
    if (!root)
    {
        root = new TreeNode(now);
        cout << father << endl;
    }
    else
    {
        if (now < root->val)
            root->leftChild = insert(root->leftChild, now, root->val);
        else
            root->rightChild = insert(root->rightChild, now, root->val);
    }
    return root;
}

int main()
{
    int n;
    int now;
    while (cin >> n)
    {
        TreeNode *root = nullptr;
        for (int i = 0; i < n; i++)
        {
            cin >> now;
            root = insert(root, now, -1);
        }
    }

    return 0;
}