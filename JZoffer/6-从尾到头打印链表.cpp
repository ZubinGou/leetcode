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
解法：
1. 使用栈保存，倒序输出
2. 使用递归结构（可能导致函数调用栈溢出）
*/

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    vector<int> printListReversingly(ListNode *head)
    {
        vector<int> res;
        while (head != nullptr) {
            res.push_back(head->val);
            head = head->next;
        }
        // reverse(res.begin(), res.end());
        // return res;
        return vector<int>(res.rbegin(), res.rend());
    }
};

int main()
{

    return 0;
}