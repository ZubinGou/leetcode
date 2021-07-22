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

// pre-order & in-order -> post-order
struct TreeNode {
    char val;
    TreeNode* leftChild;
    TreeNode* rightChild;
    TreeNode(char c): val(c), leftChild(nullptr), rightChild(nullptr) {}
};

TreeNode* build(string pre, string in, int& pre_pos) {
    int mid_pos = in.find(pre[pre_pos]);
    TreeNode* root = new TreeNode(in[mid_pos]);
    pre_pos++;
    if (mid_pos != 0)
        root->leftChild = build(pre, in.substr(0, mid_pos), pre_pos);
    if (mid_pos != in.length() - 1)
        root->rightChild = build(pre, in.substr(mid_pos + 1), pre_pos);
    return root;
}

void post_order(TreeNode* root) {
    if (root == nullptr) return;
    post_order(root->leftChild);
    post_order(root->rightChild);
    cout << root->val;
}


int main() {
    string pre;
    string in;
    while (cin >> pre >> in) {
        int pre_pos = 0;
        TreeNode* root = build(pre, in, pre_pos);
        post_order(root);
        cout << endl;
    }
    return 0;
}