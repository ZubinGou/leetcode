#include <iostream>
#include <vector>


using namespace std;

int main() {
    int n;
    // first calc all res
    vector<int> dp(36, 0);
    for (int i = 1; i <= 35; i++)
        dp[i] = dp[i - 1] * 3 + 2;

    while (cin >> n)
        cout << dp[n] << endl;   

    return 0;
}