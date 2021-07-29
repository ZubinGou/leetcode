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


class Solution {
public:
    string replaceSpaces(string &str) {
        string res = "";
        for (auto c : str) {
            if (c == ' ') res += "%20";
            else res.push_back(c);
        }
        return res;
    }
};

int main() {
    Solution sol;
    string str = "We are happy";
    cout << sol.replaceSpaces(str) << endl;
    return 0;
}