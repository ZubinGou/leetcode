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
dp
*/

class Solution {
public:
    int maxProductAfterCutting(int length) {
        vector<int> dp(length + 1, 0);
        if (length <= 0) return 0;
        if (length <= 3) return length - 1;
        
        dp[0] = 1;
        for (int i = 1; i <= length; i++) {
            for (int j = 0; j < i; j++)
                dp[i] = max(dp[i], dp[j] * (i - j));
        }
        return dp[length];
    }
};

int main() {
    Solution sol;

    cout << sol.maxProductAfterCutting(0) << endl;
    cout << sol.maxProductAfterCutting(1) << endl;
    cout << sol.maxProductAfterCutting(2) << endl;
    cout << sol.maxProductAfterCutting(8) << endl;
    cout << sol.maxProductAfterCutting(10) << endl;
    return 0;
}