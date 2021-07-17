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

const int MAX_N = 30;
int a[MAX_N];
int dp[MAX_N];

/*
最长递减子序列：
1. dp[i] 表示 i 结尾的最大字序列和

*/

int main() {
    int n;
    int res = 0;
    cin >> n;
    for (int i = 0; i < n; i++)   
        cin >> a[i];

    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (a[i] <= a[j])
                dp[i] = max(dp[i], dp[j] + 1);
        res = max(res, dp[i]);
    }
    cout << res << endl;

    return 0;
}