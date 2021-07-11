#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
// #include <unordered_map>  // can't compile on poj
#include <algorithm>
#include <string>
#include <cstring>
#include <climits>

using namespace std;

int n, p, q;
const int MAX_N = 27;
bool visited[MAX_N][MAX_N];

int direction[8][2] = {
    {-1, -2},
    {1, -2},
    {-2, -1},
    {2, -1},
    {-2, 1},
    {2, 1},
    {-1, 2},
    {1, 2},
};

bool dfs(int i, int j, int step, string path)
{
    if (step == p * q)
    {
        cout << path << endl << endl;
        return true;
    }
    // else
    for (int k = 0; k < 8; k++) {
        int new_i = i + direction[k][0];
        int new_j = j + direction[k][1];
        if (new_i < 0 || new_i >= p || new_j < 0 || new_j >= q || visited[new_i][new_j]) {
            continue;
        }
        char i_str = new_i + '1';
        char j_str = new_j + 'A';
        visited[new_i][new_j] = true;
        if (dfs(new_i, new_j, step + 1, path + j_str + i_str))
            return true;
        visited[new_i][new_j] = false;
    }
    return false;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p >> q;
        cout << "Scenario #" << i + 1 << ":" << endl;
        memset(visited, false, sizeof(visited));
        visited[0][0] = true;
        if (!dfs(0, 0, 1, "A1"))
            cout << "impossible" << endl << endl;
    }

    return 0;
}