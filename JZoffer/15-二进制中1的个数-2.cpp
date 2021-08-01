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
 n & (n-1) ：消去 n 末尾的 1
*/
class Solution
{
public:
    int NumberOf1(int n)
    {
        int res = 0;
        while (n)
        {
            res++;
            n &= n-1;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    cout << sol.NumberOf1(9) << endl;
    cout << sol.NumberOf1(-2) << endl;
    cout << sol.NumberOf1(0x7fffffff) << endl;
    cout << sol.NumberOf1(0xffffffff) << endl;
    cout << sol.NumberOf1(0x80000000) << endl;
    return 0;
}