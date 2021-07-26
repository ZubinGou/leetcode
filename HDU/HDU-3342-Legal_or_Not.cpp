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
1. 拓扑排序检测环路
2. 注意重复的边输入
*/

const int MAX_N = 1e3 + 50;

bool adj[MAX_N][MAX_N];
int ind[MAX_N];

bool topological_sort(int n)
{
    for (int i = 0; i < n; i++)
    { // all adges
        int j = 0;
        for (; j < n; j++) // 遍历所有点
            if (ind[j] == 0)
            { // 该点是否入度为0
                ind[j] = -1;
                for (int k = 0; k < n; k++)
                    if (adj[j][k])
                    {
                        // adj[j][k] = false;
                        ind[k]--;
                    }
                break;
            }
        if (j == n)
            return false;
    }
    return true;
}

int main()
{
    int n; // nodes
    int m; // edges
    int x, y;
    while (cin >> n >> m)
    {
        if (n == 0)
            break;
        memset(adj, 0, sizeof(adj));
        memset(ind, 0, sizeof(ind));
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            if (!adj[x][y])  // !!! 注意输入重复的边！
            {
                adj[x][y] = true;
                ind[y]++;
            }
        }
        if (topological_sort(n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}