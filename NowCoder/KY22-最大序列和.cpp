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
1. dp[i] 表示以 i 结尾的最大子序列和
2. 变量代替数组，内存优化为 O(1)

*/

const int MAX_N = 1e6 + 50;

// long long dp[MAX_N];

long long dp_old, dp;

int main() {
    int n;
    while (cin >> n) {
        cin >> dp_old;
        long long res = dp_old; 
        for (int i = 1; i < n; i++) {
            cin >> dp;
            if (dp_old > 0)
                dp += dp_old;

            res = max(res, dp);
            dp_old = dp;
        }
        cout << res << endl;
    }
   return 0;
}