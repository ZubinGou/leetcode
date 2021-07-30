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
DFS / BFS
1. visited 数组
2. 边界范围
3. 数位和 < threshold
*/

class Solution
{
private:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int count = 0;
    int get_sum(int a, int b)
    {
        int res = 0;
        while (a)
        {
            res += a % 10;
            a /= 10;
        }
        while (b)
        {
            res += b % 10;
            b /= 10;
        }
        return res;
    }

    int dfs(int threshold, int rows, int cols, int i, int j, vector<vector<bool>> &visited)
    {
        count++;
        visited[i][j] = true;
        for (auto d : directions)
        {
            int ni = i + d[0];
            int nj = j + d[1];
            if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && !visited[ni][nj] && get_sum(ni, nj) <= threshold)
                dfs(threshold, rows, cols, ni, nj, visited);
        }
    }

public:
    int movingCount(int threshold, int rows, int cols)
    {
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        if (threshold < 0 || rows <= 0 || cols <= 0)
            return 0;
        dfs(threshold, rows, cols, 0, 0, visited);
        return count;
    }
};

int main()
{
    Solution sol;
    // cout << sol.movingCount(7, 4, 5) << endl;
    cout << sol.movingCount(18, 40, 40) << endl;
    // cout << sol.movingCount(17, 40, 40) << endl;
    return 0;
}