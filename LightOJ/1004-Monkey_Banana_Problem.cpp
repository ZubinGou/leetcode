#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N = 2e2 + 50;

int dp[MAX_N][MAX_N];

int main()
{
    int t, n;
    cin >> t;
    for (int case_num = 1; case_num <= t; case_num++)
    {
        cin >> n;
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= i; j++)
            {
                cin >> dp[i][j];
                dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
            }

        for (int i = n + 1; i < 2 * n; i++)
            for (int j = 1; j <= 2 * n - i; j++)
            {
                cin >> dp[i][j];
                dp[i][j] += max(dp[i - 1][j + 1], dp[i - 1][j]);
            }

        cout << "Case " << case_num << ": " << dp[2 * n - 1][1] << endl;
    }
}