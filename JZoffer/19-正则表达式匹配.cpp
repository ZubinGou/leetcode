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
1. "." 匹配 str 下一个字
2. "x*" 匹配 (1) 空 (2) x + "*"
3. ".*" 匹配 (1) 空 (2) str 下一个字 + ".*"

? 连续 "*"
*/

class Solution
{
private:
    bool match(string s, string p, int i, int j)
    {
        if (i == s.length() && j == p.length())
            return true;
        if (i != s.length() && j == p.length())
            return false;

        if (j + 1 < p.length() && p[j + 1] == '*')
        {
            if (s[i] == p[j] || p[j] == '.' && i < s.length()) // match
                return match(s, p, i, j + 2) || match(s, p, i + 1, j);
            else
                return match(s, p, i, j + 2);
        }
        else
            return (s[i] == p[j] || p[j] == '.' && i < s.length()) && match(s, p, i + 1, j + 1);
    }

public:
    bool isMatch(string s, string p)
    {
        return match(s, p, 0, 0);
    }
};

int main()
{
    Solution sol;
    cout << sol.isMatch("aa", "a*") << endl;
    cout << sol.isMatch("", ".*") << endl;
    return 0;
}