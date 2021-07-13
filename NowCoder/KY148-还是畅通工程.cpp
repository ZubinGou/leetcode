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
1. Kruskal 最小生成树
2. 并查集
*/

const int MAX_N = 105;

struct Edge
{
    int from;
    int to;
    int length;
    bool operator<(const Edge &e) const
    {
        return length < e.length;
    }
};

bool cmp(const Edge a, const Edge b) {
    return a.length < b.length;
}

int father[MAX_N], height[MAX_N];
Edge edge[MAX_N * MAX_N / 2];

void Initial(int n)
{
    for (int i = 0; i <= n; i++)
    {
        father[i] = i;
        height[i] = 0;
    }
}

int Find(int x)
{
    if (father[x] != x)
    {
        father[x] = Find(father[x]); // memory
    }
    return father[x];
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x != y)
    { // lower tree as subtree of the higher
        if (height[x] < height[y])
            father[x] = y;
        else if (height[x] > height[y])
            father[y] = x;
        else
        {
            father[y] = x;
            height[x]++;
        }
    }
    return;
}

int Kruskal(int n, int edge_count)
{
    int res = 0;  // @return MST min length sum
    int added = 0; // already added edge
    sort(edge, edge + edge_count);
    for (int i = 0; i < edge_count; i++) {
        if (added == n - 1)
            break;
        Edge cur_edge = edge[i];
        if (Find(cur_edge.from) != Find(cur_edge.to)) {
            Union(cur_edge.from, cur_edge.to);
            res += cur_edge.length;
            added++;
        }
    }
    return res;
}

int main()
{
    int n, m;
    int a, b, length;
    while (cin >> n)
    {
        if (n == 0)
            break;
        Initial(n);
        int edge_count = n * (n - 1) / 2;
        for (int i = 0; i < edge_count; i++)
            cin >> edge[i].from >> edge[i].to >> edge[i].length;
        cout << Kruskal(n, edge_count) << endl;
    }
    return 0;
}