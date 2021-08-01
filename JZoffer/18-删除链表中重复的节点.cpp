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

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printNodes(ListNode *head)
{
    ListNode *now = head;
    while (now)
    {
        cout << now->val << " ";
        now = now->next;
    }
    cout << endl;
}

class Solution
{
public:
    ListNode *deleteDuplication(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *res = head;
        ListNode *preNode = nullptr;
        ListNode *curNode = head;

        while (curNode)
        {
            if (curNode->next && curNode->next->val == curNode->val)
            { // delete all repeat
                int val = curNode->val;
                while (curNode && curNode->val == val)
                { // delete curNode
                    ListNode *temp = curNode->next;
                    delete curNode;
                    curNode = temp;
                }
                if (preNode == nullptr)
                    res = curNode;
                else
                    preNode->next = curNode;
            }
            else
            { // pass
                preNode = curNode;
                curNode = curNode->next;
            }
        }
        return res;
    }
};

int main()
{
    // vector<int> nodes = {1, 3, 3, 4, 4, 5};
    vector<int> nodes = {1, 1, 1, 2, 2, 3, 5};
    ListNode *head = new ListNode(nodes[0]);
    ListNode *cur = head;
    for (int i = 1; i < nodes.size(); i++)
    {
        cur->next = new ListNode(nodes[i]);
        cur = cur->next;
    }
    cout << "before: ";
    printNodes(head);

    Solution sol;
    ListNode *res = sol.deleteDuplication(head);

    cout << "after: ";
    printNodes(res);

    return 0;
}