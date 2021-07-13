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
1. 连通图计数
2. 并查集：合并邻接的点，最后计算集合数量
*/

const int MAX_N = 1000;

int father[MAX_N], height[MAX_N];

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

int main()
{
    int n, m;
    int a, b;
    while (cin >> n >> m)
    {
        if (n == 0)
            break;
        Initial(n);
        while (m--)
        {
            cin >> a >> b;
            Union(a, b);
        }
        int component_count = 0;
        for (int i = 1; i <= n; i++)
            if (Find(i) == i)
                component_count++;

        if (component_count == 1)
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    } 
    return 0;
}