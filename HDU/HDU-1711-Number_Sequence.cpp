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
KMP：
1. Partial Match Table（PMT）：前缀后缀最大交集
2. Next 数组为 PMT 向后偏移一位
3. 当 pattern 的 j 位失配，则 j = PMT[j - 1] = Next[j]
*/

const int MAX_N = 1e6 + 50;

int str[MAX_N];
int pattern[MAX_N];
int nxt[MAX_N];

void get_next(int m)
{
    nxt[0] = -1;
    int i = 0, j = -1;
    while (i < m)
    {
        if (j == -1 || pattern[i] == pattern[j])
        {
            i++;
            j++;
            nxt[i] = j;
        }
        else
            j = nxt[j];
    }
}

int kmp(int n, int m)
{
    get_next(m);
    int i = 0;
    int j = 0;
    while (i < n && j < m)
    {
        if (j == -1 || str[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
            j = nxt[j];
    }
    if (j == m)
        return i - j + 1;
    else
        return -1;
}

int main()
{
    int T;
    int n, m;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
            scanf("%d", &str[i]);
        for (int i = 0; i < m; i++)
            scanf("%d", &pattern[i]);
        printf("%d\n", kmp(n, m));
    }

    return 0;
}