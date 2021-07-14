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

const int MAX_N = 205;
const int INF = 1e9;

/*
dijkstra O(VlogV + E)

复杂度：
1. 找最短距离：查找 O(1)，更新 O(logV)
2. 更新距离：O(2 * E)，每条边只有俩端点，最多更新两次

注意：C++的 priority_queue 默认为最大堆，需要重载 < 运算符编程最小堆
*/

struct Node
{
    int to;
    int dist;
    Node(int a, int b)
    {
        to = a;
        dist = b;
    }
    bool operator<(const Node &n) const
    {
        return n.dist < dist;
    }
};

int n;
int adj[MAX_N][MAX_N];
int dist[MAX_N];
bool visited[MAX_N];

// int min_dist()
// {
//     int min_val = INF, min_index = 0;
//     for (int i = 0; i < n; i++) {
//         if (!visited[i] && dist[i] <= min_val) {
//             min_val = dist[i];
//             min_index = i;
//         }
//     }
//     return min_index;
// }

void dijkstra(int src)
{
    priority_queue<Node> q;

    // init dist and visited
    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[src] = 0;
    q.push(Node(src, 0));
    while (!q.empty()) {
        Node now = q.top();
        q.pop();
        int u = now.to;
        if (visited[u])
            continue;
        visited[u] = true;
        // update adj
        if (dist[u] != INF)
            for (int v = 0; v < n; v++)
                if (!visited[v] && adj[u][v] != INF && dist[u] + adj[u][v] < dist[v]) {
                    dist[v] =  dist[u] + adj[u][v];
                    q.push(Node(v, dist[v]));
                }
    }
}

int main()
{
    int m;
    int a, b, x;
    int start, end;
    while (cin >> n >> m)
    {
        // init
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i == j)
                    adj[i][i] = 0;
                else
                    adj[i][j] = INF;

        for (int i = 0; i < m; i++)
        {
            cin >> a >> b >> x;
            if (adj[a][b] > x)
                adj[a][b] = adj[b][a] = x;
        }
        cin >> start >> end;

        dijkstra(start);

        if (dist[end] == INF)
            cout << -1 << endl;
        else
            cout << dist[end] << endl;
    }
    return 0;
}