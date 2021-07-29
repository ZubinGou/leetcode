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

class MyQueue
{
private:
    stack<int> in_stack;
    stack<int> out_stack;

public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x) // o(n)
    {
        // out -> in
        while (!out_stack.empty()) {
            in_stack.push(out_stack.top());
            out_stack.pop();
        }
        // x -> out
        out_stack.push(x);
        // in -> out
        while (!in_stack.empty()) {
            out_stack.push(in_stack.top());
            in_stack.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() // o(1)
    {
        if (!out_stack.empty())
        {
            int res = out_stack.top();
            out_stack.pop();
            return res;
        }
        else
            return -1;
    }

    /** Get the front element. */
    int peek() // o(1)
    {
        if (!out_stack.empty())
        {
            return out_stack.top();
        }
        else
            return -1;
    }

    /** Returns whether the queue is empty. */
    bool empty() // o(1)
    {
        return out_stack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */

int main()
{

    MyQueue queue = MyQueue();

    queue.push(1);
    queue.push(2);
    cout << queue.peek() << endl;  // returns 1
    cout << queue.pop() << endl;   // returns 1
    cout << queue.empty() << endl; // returns false
    return 0;
}