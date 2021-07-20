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

const int MAX_N = 1e4 + 50;
const int INF = INT_MAX / 10;

int n;
int weight_total;
int value[MAX_N];
int weight[MAX_N];
int dp[MAX_N];

/*
完全背包
注意求 min 则修改 dp 数组初始化 和 状态转移方程
*/


int main() {
    int T;
    int weight_empty, weight_filled;
    cin >> T;
    while (T--) {
        cin >> weight_empty >> weight_filled;
        weight_total = weight_filled - weight_empty;
        cin >> n;
        
        for (int i = 0; i < n; i++)
            cin >> value[i] >> weight[i];
        
        // memset(dp, -1, sizeof(dp)); // memset can only set 0 or -1, because memset works byte by byte
        for (int i = 1; i <= weight_total; i++)
            dp[i] = INF;
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = weight[i]; j <= weight_total; j++) {  // 0-1 背包为反序遍历，完全背包为正序遍历
                dp[j] = min(dp[j], dp[j - weight[i]] + value[i]);
            }
        }
        if (dp[weight_total] == INF)
            cout << "This is impossible." << endl;
        else
            cout << "The minimum amount of money in the piggy-bank is " << dp[weight_total] << "." << endl;
    }

    return 0;
}