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
1. 首先对 gap 和 bridge 按长度从小达到排序
2. 从小到达遍历 bridge，在 gap 区间满足当前桥长度的 gap 里选择 max_length 最小的gap
*/

const int MAX_N = 2e5 + 50;

struct Bridge
{
    long long length;
    long long max_length;
    int idx;
    bool operator<(Bridge b) const
    {
        return max_length > b.max_length;
    }
};

Bridge bridge[MAX_N]; // m bridges
Bridge gap[MAX_N];    // n - 1 gaps

int res[MAX_N];

bool cmp(Bridge a, Bridge b)
{
    return a.length < b.length;
}

bool solve(int n, int m)
{
    priority_queue<Bridge> gap_queue;
    int j = 0; // gap index
    int res_count = 0;
    for (int i = 0; i < m; i++)
    {
        while (j < n - 1 && bridge[i].length >= gap[j].length && bridge[i].length <= gap[j].max_length)
            gap_queue.push(gap[j++]);
        if (!gap_queue.empty())
        {
            Bridge gap_now = gap_queue.top();
            if (gap_now.length > bridge[i].length || gap_now.max_length < bridge[i].length)
                break;
            gap_queue.pop();
            res[gap_now.idx] = bridge[i].idx;
            res_count++;
        }
    }
    return res_count == n - 1;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    long long now_begin, now_end, last_begin, last_end;
    scanf("%lld %lld", &last_begin, &last_end);

    for (int i = 0; i < n - 1; i++)
    { // n - 1 gaps
        scanf("%lld %lld", &now_begin, &now_end);
        gap[i].length = now_begin - last_end;
        gap[i].max_length = now_end - last_begin;
        gap[i].idx = i;
        last_end = now_end;
        last_begin = now_begin;
    }

    for (int i = 0; i < m; i++)
    { // m bridges
        scanf("%lld", &bridge[i].length);
        bridge[i].max_length = 0;
        bridge[i].idx = i + 1;
    }

    sort(gap, gap + n - 1, cmp);
    sort(bridge, bridge + m, cmp);

    if (solve(n, m))
    {
        printf("Yes\n");
        for (int i = 0; i < n - 1; i++)
            printf("%d ", res[i]);
    }
    else
    {
        printf("No\n");
    }
    return 0;
}