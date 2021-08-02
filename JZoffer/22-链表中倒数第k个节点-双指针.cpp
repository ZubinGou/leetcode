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
双指针解法
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
        if (pListHead == nullptr || k == 0) return nullptr;
        ListNode *pAhead = pListHead;
        ListNode *pBehind = pListHead;
        // ahead go
        for (int i = 0; i < k - 1; i++) {
            if (pAhead->next == nullptr) return nullptr;
            else pAhead = pAhead->next;
        }
        // together go
        while (pAhead->next) {
            pAhead = pAhead->next;
            pBehind = pBehind->next;
        }

        return pBehind;
    }
};

int main()
{

    return 0;
}