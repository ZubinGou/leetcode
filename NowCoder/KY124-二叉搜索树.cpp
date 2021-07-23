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
    char val;
    TreeNode *leftChild;
    TreeNode *rightChild;
    TreeNode(char v) : val(v), leftChild(nullptr), rightChild(nullptr) {}
};

TreeNode *build(TreeNode *root, char val)
{
    if (!root)
        root = new TreeNode(val);
    else
    {
        if (val < root->val)
            root->leftChild = build(root->leftChild, val);
        else
            root->rightChild = build(root->rightChild, val);
    }
    return root;
}

TreeNode *build_from_str(string str)
{
    TreeNode *root = nullptr;
    for (char c : str) {
        root = build(root, c);
    }
    return root;
}

bool is_same_tree(TreeNode *a, TreeNode *b)
{
    if (!a && !b)
        return true;
    return a->val == b->val && is_same_tree(a->leftChild, b->leftChild) && is_same_tree(a->rightChild, b->rightChild);
}

int main()
{
    int n;
    string str;
    while (cin >> n)
    {
        if (n == 0)
            break;
        // build origin tree
        cin >> str;
        TreeNode *root = build_from_str(str);

        // judge other tree
        for (int i = 0; i < n; i++)
        {
            cin >> str;
            TreeNode *root_new = build_from_str(str);
            if (is_same_tree(root, root_new))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}
