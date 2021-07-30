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
1. 观察发现：矩阵右上角的数：大于所在行其他数，小于所在列其他数，可以用来逐行逐列排除
*/

class Solution
{
public:
    bool searchArray(vector<vector<int>> array, int target)
    {
        int m = array.size(); // row
        if (m == 0)
            return false;
        int n = array[0].size();
        if (n == 0)
            return false; // column

        int i = 0, j = n - 1;
        while (i < m && j >= 0)
        {
            int now = array[i][j];
            if (now == target)
                return true;
            else if (now > target)
                j--;
            else
                i++;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> array = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    int target1 = 5;
    int target2 = 7;
    cout << sol.searchArray(array, target1) << endl;
    cout << sol.searchArray(array, target2) << endl;
    return 0;
}