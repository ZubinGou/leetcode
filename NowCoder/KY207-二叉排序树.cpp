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

int insert(TreeNode *root, int now)
{
    // return father
    if (now < root->val)
    {
        if (root->leftChild)
            return insert(root->leftChild, now);
        else
        {
            root->leftChild = new TreeNode(now);
            return root->val;
        }
    }
    else
    {
        if (root->rightChild)
            return insert(root->rightChild, now);
        else
        {
            root->rightChild = new TreeNode(now);
            return root->val;
        }
    }
}

int main()
{
    int n;
    int now;
    while (cin >> n)
    {
        if (n == 0)
            continue;
        // input the root
        cin >> now;
        TreeNode *root = new TreeNode(now);
        cout << -1 << endl;
        // input the rest
        for (int i = 1; i < n; i++)
        {
            cin >> now;
            cout << insert(root, now) << endl;
        }
    }

    return 0;
}