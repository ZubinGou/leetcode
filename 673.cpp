#include <iostream>
#include <climits>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        vector<int> count(n);
        int max_dp = 1;
        for (int i = 0; i < n; i++) {
            dp[i] = count[i] = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] < nums[i]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }
                    else if (dp[j] + 1 == dp[i]) {
                        count[i] += count[j];
                    }
                }
            }
            max_dp = max(max_dp, dp[i]);
        }
        
        cout << max_dp << endl;
        for (int i = 0; i < n; i++)
            cout << "count[" << i << "] = " << count[i] << endl;
            
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == max_dp) {
                res += count[i];
            }
        }
        
        return res;
        
    }
};

int main() {
    Solution sol;
    vector<int> nums({1,1,1,2,2,2,3,3,3});
    int res = sol.findNumberOfLIS(nums);
    cout << res;
}