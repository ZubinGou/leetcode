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
int n;

int matrix[MAX_N][MAX_N];
int sum[MAX_N][MAX_N];
int arr[MAX_N];
int dp[MAX_N];

int max_sub_sequence() {
    int res;
    res = dp[0] = arr[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(arr[i], arr[i] + dp[i - 1]);
        res = max(res, dp[i]);
    }
    return res;
}

int max_sub_matrix() {
    int maximum = INT_MIN;
    // get sum 
    memset(sum, 0, sizeof(sum));
    for (int i = 0; i < n; i++) {  // row
        for (int j = 0; j < n; j++) {  // col
            sum[i + 1][j] = sum[i][j] + matrix[i][j];
        }
    }
    
    // get max
    for (int i = 0; i < n; i++) {  // start row
        for (int j = i; j < n; j++) {  // end row
            for (int k = 0; k < n; k++)  // get arr
                arr[k] = sum[j + 1][k] - sum[i][k];
            maximum = max(maximum, max_sub_sequence());
        }
    }
    
    return maximum;
}

int main() {

    while (cin >> n) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        
        cout << max_sub_matrix() << endl;
    }

    return 0;
}