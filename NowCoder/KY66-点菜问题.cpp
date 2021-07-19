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

const int MAX_N = 1e3 + 50;

int dp[MAX_N];
int value[MAX_N];
int cost[MAX_N];

/*
dp[i][j]： 容量 j -> 最大价值
*/


int main() {
    int budget, n;
    while (cin >> budget >> n) {
        for (int i = 0; i < n; i++)
            cin >> cost[i] >> value[i];

        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < n; i++)
            for (int j = budget; j >= cost[i]; j--)
                dp[j] = max(dp[j], dp[j - cost[i]] + value[i]);
        
        cout << dp[budget] << endl;
    }

    return 0;
}