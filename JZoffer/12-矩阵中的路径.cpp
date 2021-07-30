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
private:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    bool backtrace(vector<vector<char>> &matrix, string &str, int pos, int i, int j, vector<vector<bool>> &visited)
    {
        // cout << "back pos=" << pos << " " << i << " " << j << endl;
        if (str[pos] != matrix[i][j])
            return false;
        if (pos == str.length() - 1 && str[pos] == matrix[i][j])
        {
            return true; // end
        }
        visited[i][j] = true;

        for (auto d : directions)
        {
            int new_i = i + d[0];
            int new_j = j + d[1];
            if (pos < str.length() - 1 && new_i >= 0 && new_i < matrix.size() && new_j >= 0 && new_j < matrix[0].size() && !visited[new_i][new_j])
            {
                if (backtrace(matrix, str, pos + 1, new_i, new_j, visited))
                    return true;
            }
        }
        visited[i][j] = false;
        return false;
    }

    bool hasPath(vector<vector<char>> &matrix, string &str)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0 || str.length() == 0)
            return false;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (backtrace(matrix, str, 0, i, j, visited))
                    return true;
            }
        }
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