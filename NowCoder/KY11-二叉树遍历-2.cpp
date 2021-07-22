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

// pre-order -> in-order

int main()
{
    string pre;
    cin >> pre;
    stack<char> s;
    for (auto it : pre)
    {
        if (it != '#')
            s.push(it);
        else if (!s.empty())  // '#
        {
            cout << s.top() << ' ';
            s.pop();
        }
    }
}