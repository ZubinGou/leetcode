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

const int MAX_N = 105;

int dp[MAX_N];

int main() {
    int n;
    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    cout << dp[n];
    return 0;
}