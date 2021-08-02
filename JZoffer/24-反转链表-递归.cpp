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
递归版本
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
private:
    ListNode* reverseRec(ListNode* head, ListNode* next) {
        ListNode* temp = head->next;
        head->next = next;
        if (temp) return reverseRec(temp, head);
        else return head;
    }
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        return reverseRec(head, nullptr);
    }
};

int main()
{

    return 0;
}