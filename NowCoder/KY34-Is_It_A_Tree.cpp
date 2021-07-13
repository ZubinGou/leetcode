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
3. 树满足：所有非根结点入度为1，只有一个根
*/

const int MAX_N = 10050;

int father[MAX_N];
int height[MAX_N];
int in_degree[MAX_N];
bool visit[MAX_N];

void Initial(int n)
{
    for (int i = 0; i < n; i++)
    {
        father[i] = i;
        height[i] = 0;
        in_degree[i] = 0;
        visit[i] = false;
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

bool isTree()
{
    int root_count = 0;
    int component_count = 0;
    bool flag = true;
    for (int i = 0; i < MAX_N; i++)
    {
        if (!visit[i])
            continue;
        if (Find(i) == i)
            component_count++;

        if (in_degree[i] == 0)
            root_count++;
        else if (in_degree[i] > 1)
            flag = false;
    }
    if (component_count != 1 || root_count != 1)
        flag = false;
    if (component_count == 0 && root_count == 0)
        flag = true;
    return flag;
}

int main()
{
    int a, b;
    int case_i = 0;
    Initial(MAX_N);
    while (cin >> a >> b)
    {
        if (a == -1)
            break;
        else if (a == 0 && b == 0)
        {
            if (isTree())
                cout << "Case " << ++case_i<< " is a tree." << endl;
            else
                cout << "Case " << ++case_i << " is not a tree." << endl;
            Initial(MAX_N);
        }
        else
        {
            Union(a, b);
            in_degree[b]++;
            visit[a] = true;
            visit[b] = true;
        }
    }
    return 0;
}