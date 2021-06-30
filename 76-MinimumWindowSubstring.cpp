#include <iostream>
#include <climits>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        string res = "";
        vector<int> count(128, 0);
        int left = 0;
        int right = 0;
        int minLeft = 0;
        int minLen = INT_MAX;
        int cnt = 0;
        cout << count['a'] << endl;
        for (char c : t) {
            // if (count[c] < 0) 
            //     count[c] = 1;
            // else
            //     count[c]++;
            count[c]++;
            cnt++;
        }
        while (right < s.size()) {
            if (count[s[right++]]-- > 0)
                cnt--;
            while (cnt == 0) {
                if (right - left < minLen) {
                    minLen = right - left;
                    minLeft = left;
                }
                cout << count[s[left]] << endl;
                if (++count[s[left++]] > 0) {
                    cout << "h1： " << s[left - 1] << endl;
                    cnt++;
                }
            }
        }
        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
    }
};

int main()
{
    Solution sol;
    string minStr = sol.minWindow("ADOBECODBAN", "ABC");
    cout << minStr << endl;
}