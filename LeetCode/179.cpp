#include <iostream>
#include <climits>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    static bool sort_str(const string &lhs, const string &rhs) 
    {
        cout << "cmp, " << lhs << " " << rhs << endl;
        if (rhs[0] != lhs[0])
            return lhs[0] > rhs[0];
        if (lhs.length() > 1 && rhs.length() > 1)
            return sort_str(lhs.substr(1), rhs.substr(1));
        if (lhs.length() != rhs.length() && lhs[0] == rhs[0]) {
            cout << "hr" << endl;
            if (lhs.length() == 1)
                return lhs[0] >= rhs[1];
            else
                return lhs[1] > rhs[0];
        }
        return lhs > rhs;
    }
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (auto i : nums) {
            strs.push_back(to_string(i));
        }
        string res = "";
        sort(strs.begin(), strs.end(), sort_str);
        for (auto s : strs) {
            res += s;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3,30,34,5,9};
    cout << sol.largestNumber(nums);
}