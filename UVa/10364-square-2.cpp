// #include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <map>
// #include <unordered_map>  // can't compile on poj
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX_M = 30;

int n, m, sum, avg;
int a[MAX_M];
bool visited[MAX_M];

/*********************************
 * 剪枝：
 * 1. 总长不整除4
 * 2. 最长棍长度大于边长
 * 3. 对无法构成当前边的长度，再次遇到时跳过
*********************************/



bool dfs(int step, int cur_len, int pos)
{
    if (step == 3)
    {
        return true;
    }
    // else
    int sample = 0; // 剪枝（3）
    for (int i = pos; i < m; i++)
    {
        if (visited[i] || cur_len + a[i] > avg || a[i] == sample)
            continue;

        visited[i] = true;
        if (cur_len + a[i] == avg)
        { // next step
            if (dfs(step + 1, 0, 0))
                return true;
            else
                sample = a[i];
        }
        else if (cur_len + a[i] < avg)
        {
            if (dfs(step, cur_len + a[i], i + 1))
                return true;
            else
                sample = a[i];
        }

        visited[i] = false;
    }
    return false;
}

int main()
{
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &m);
        sum = 0;
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        if (sum % 4 != 0)
        { // 剪枝（1）
            printf("no\n");
            continue;
        }

        sort(a, a + m, greater<int>());
        avg = sum / 4;
        if (a[0] > avg)
        { // 剪枝（2）
            printf("no\n");
            continue;
        }

        memset(visited, false, sizeof(visited));
        if (dfs(0, 0, 0))
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}