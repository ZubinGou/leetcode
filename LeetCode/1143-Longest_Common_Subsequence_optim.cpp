/*
空间优化： O(N^2) -> O(N)
（非滚动数组）
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length();
        int len2 = text2.length();
        
        int dp[len2 + 1];
        memset(dp, 0, sizeof(dp)); 
        for (int i = 1; i <= len1; i++) {
            int oldval = 0;
            for (int j = 1; j <= len2; j++) {
                int temp = dp[j]; 
                if (text1[i - 1] == text2[j - 1]) {
                    dp[j] = oldval + 1;
                }
                else {
                    dp[j] = max(dp[j - 1], dp[j]);   
                }
                oldval = temp;
            }
        }
        return dp[len2];
        
    }