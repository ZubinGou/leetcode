#include <iostream>
#include <climits>

using namespace std;


int main()
{
    int n;
    cin >> n;
    int a[n + 1];
    int dp[n + 1][n + 1];

    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
        cin >> a[i];
    }
    dp[n][n] = 0;

    for (int gap = 2; gap < n; gap++) {
        for (int i = 1; i <= n - gap + 1; i++) {
            int min_val = INT_MAX;
            int j = i + gap - 1;
            for (int k = i; k < j; k++) {
                min_val = min(min_val, dp[i][k] + dp[k + 1][j] + a[i - 1] * a[k] * a[j]);
            }
            dp[i][j] = min_val;
        }
    }
    cout << dp[1][n - 1] << endl;
    // return dp[1][n-1];
} 