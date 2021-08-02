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
先计数 n，再移动到 k
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
    ListNode *findKthToTail(ListNode *pListHead, int k)
    {
        if (k == 0) return nullptr;
        int n = 0;
        ListNode *p = pListHead;
        while (p)
        {
            p = p->next;
            n++;
        }
        p = pListHead;
        if (n < k)
            return nullptr;
        for (int i = 0; i < n - k; i++)
            p = p->next;
        return p;
    }
};

int main()
{

    return 0;
}