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

const int MAX_N = 1e2 + 50;

int dp[MAX_N][MAX_N];


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> dp[i][j];
        }
    }

    for (int i = n - 2; i >= 0; i--)
        for (int j = 0; j <= i; j++)
            dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1]);

    cout << dp[0][0] << endl;

    return 0;
}