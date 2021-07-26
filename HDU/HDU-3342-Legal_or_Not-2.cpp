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

vector<int> adj[MAX_N];
int ind[MAX_N];

bool topological_sort(int n)
{
    stack<int> zero_ind;
    for (int i = 0; i < n; i++)
        if (ind[i] == 0)
            zero_ind.push(i);

    int count = 0;
    while (!zero_ind.empty()) {
        int u = zero_ind.top();
        zero_ind.pop();
        count++;
        for (auto v : adj[u]) {
            ind[v]--;
            if (ind[v] == 0)
                zero_ind.push(v);
        }
    }
    return count == n;
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
            adj[x].push_back(y);
            ind[y]++;
        }
        if (topological_sort(n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}