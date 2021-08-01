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

class Solution
{
public:
    int NumberOf1(int n)
    {
        int res = 0;
        int flag = 1;
        while (flag)
        {
            res += (n & flag) ? 1 : 0;
            flag <<= 1;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    cout << sol.NumberOf1(9) << endl;
    cout << sol.NumberOf1(-2) << endl;
    return 0;
}