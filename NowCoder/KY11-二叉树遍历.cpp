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

struct TreeNode {
    char val;
    TreeNode* leftChild;
    TreeNode* rightChild;
    TreeNode(char c): val(c), leftChild(nullptr), rightChild(nullptr) {}
};


// recursive
TreeNode* build(string str, int& pos) {
    if (str[pos++] == '#') return nullptr;
    TreeNode* root = new TreeNode(str[pos - 1]);
    root->leftChild = build(str, pos);
    root->rightChild = build(str, pos);
    return root;
}

string pre;  
while(cin >> pre){
        stack<char> s;
        for(auto it : pre){
            if(it != '#')
                s.push(it);
            else{
                if(!s.empty()){
                    cout << s.top() << ' ';
                    s.pop();
                }
            }
        }
        cout << '\n';  }

void in_order(TreeNode* root) {
    if (root == nullptr) return;
    in_order(root->leftChild);
    cout << root->val << " ";
    in_order(root->rightChild);
    return;
}


int main() {
    string str;
    cin >> str;
    int pos = 0;
    TreeNode* root = build(str, pos);
    in_order(root);
    return 0;
}