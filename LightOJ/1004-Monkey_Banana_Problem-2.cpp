#include <iostream>
#include <cstring>

using namespace std;

/*
O(N) 空间优化
*/

const int MAX_N = 2e2 + 50;

int dp[MAX_N];

int main()
{
    int t, n;
    cin >> t;
    for (int case_num = 1; case_num <= t; case_num++)
    {
        cin >> n;
        memset(dp, 0, sizeof(dp));

        int now, last = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                cin >> now;
                int temp = dp[j];
                dp[j] = now + max(last, dp[j]);
                last = temp;
            }
        }

        for (int i = n + 1; i < 2 * n; i++)
            for (int j = 1; j <= 2 * n - i; j++)
            {
                cin >> now;
                dp[j] = now + max(dp[j + 1], dp[j]);
            }

        cout << "Case " << case_num << ": " << dp[1] << endl;
    }
}