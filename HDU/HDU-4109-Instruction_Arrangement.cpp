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
1. Activity on Edge Network (AOE)
2. 关键路径：最长的源点到汇点的路径
*/

const int MAX_N = 1e3 + 50;
int adj[MAX_N][MAX_N];
int in_degree[MAX_N];
int begin_time[MAX_N];

int critical_path(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (in_degree[j] == 0)
            {
                in_degree[j] = -1;
                for (int k = 0; k < n; k++)
                {
                    if (adj[j][k])
                    {
                        in_degree[k]--;
                        begin_time[k] = max(begin_time[k], begin_time[j] + adj[j][k]);
                        // cout << "begin_time = " << begin_time[k] << endl;
                    }
                }
                break;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = max(res, begin_time[i]);
    }
    return res + 1;
}

int main()
{
    int n; // nodes
    int m; // edges
    int x, y, z;
    while (cin >> n >> m)
    {
        memset(adj, 0, sizeof(adj));
        memset(in_degree, 0, sizeof(in_degree));
        memset(begin_time, 0, sizeof(begin_time));

        for (int i = 0; i < m; i++)
        {

            cin >> x >> y >> z;
            adj[x][y] = z;
            in_degree[y]++;
        }
        cout << critical_path(n) << endl;
    }

    return 0;
}