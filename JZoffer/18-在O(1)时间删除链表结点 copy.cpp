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
题目假设节点不是尾节点

1. 将下一个节点值复制到当前节点
2. 当前指针指向下一节点的下一节点
3. 删除下一节点
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
    void deleteNode(ListNode *node)
    {
        if (!node) return;
        node->val = node->next->val;
        ListNode *temp = node->next;
        node->next = node->next->next;
        delete temp;
        temp = nullptr;
    }
};

int main()
{
    return 0;
}