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
DFS，复杂度 O(M * N * 3^K)
M行，N列，K为字符串长度
1. 将使用过的单词改为特殊符号
*/

class Solution
{
public:
    bool backtrace(vector<vector<char>> &matrix, string &str, int pos, int i, int j)
    {
        // cout << "back pos=" << pos << " " << i << " " << j << endl;
        if (str[pos] != matrix[i][j])
            return false;
        if (pos == str.length() - 1)
            return true; // end

        int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
        char temp = matrix[i][j];
        matrix[i][j] = '*';
        for (int k = 0; k < 4; k++)
        {
            int new_i = i + dx[k];
            int new_j = j + dy[k];
            if (new_i >= 0 && new_i < matrix.size() && new_j >= 0 && new_j < matrix[0].size())
                if (backtrace(matrix, str, pos + 1, new_i, new_j))
                    return true;
        }
        matrix[i][j] = temp;
        return false;
    }

    bool hasPath(vector<vector<char>> &matrix, string &str)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0 || str.length() == 0)
            return false;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (backtrace(matrix, str, 0, i, j))
                    return true;
        return false;
    }
};

int main()
{
    Solution sol;
    // vector<vector<char>> matrix = {
    // {'A', 'B', 'C', 'E'},
    // {'S', 'F', 'C', 'S'},
    // {'A', 'D', 'E', 'E'}};
    // string str = "BCCE";

    vector<vector<char>> matrix = {{'E', 'E', 'K', 'U', 'L', 'K', 'H', 'U', 'O'},
                                   {'T', 'F', 'G', 'C', 'X', 'H', 'S', 'G', 'K'},
                                   {'F', 'Z', 'Y', 'Q', 'H', 'F', 'P', 'E', 'I'}};
    string str = "GCX";

    cout << sol.hasPath(matrix, str) << endl;
    return 0;
}