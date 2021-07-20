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
多重背包：将物品拆成 2的幂之和，转换为 0-1背包
*/

const int MAX_N = 1e3 + 50;

int cost[MAX_N], weight[MAX_N];
int dp[MAX_N];

int main() {
    int t;
    int budget, n;
    cin >> t;
    while (t--) {
        cin >> budget >> n;
        int k = 0;
        int cost_now, weight_now, counts_now;
        for (int i = 0; i < n; i++) {
            cin >> cost_now >> weight_now >> counts_now;
            for (int j = 1; j < counts_now; j << 1) {
                cost[k] = cost_now * j;
                weight[k] = weight_now * j;
                k++;
                counts_now -= j;
            }
            // remain 
            if (counts_now > 0) {
                cost[k] = cost_now * counts_now;
                weight[k] = weight_now * counts_now;
                k++;
            }
        }
        // 0-1 Knapsack
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < k; i++) {
            for (int j = budget; j >= cost[i]; j--) {
                dp[j] = max(dp[j], dp[j - cost[i]] + weight[i]);
            }
        }
        cout << dp[budget] << endl;
    }

    return 0;
}