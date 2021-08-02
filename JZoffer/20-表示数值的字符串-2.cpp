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
原书解答，更加简洁
*/

class Solution {
private:
    bool matchUint(string s, int &pos) {
        if (pos >= s.length() || !isdigit(s[pos])) return false;
        while (isdigit(s[pos])) pos++;
        return true;
    }
    bool matchInt(string s, int &pos) {
        if (pos >= s.length()) return false;
        if (s[pos] == '+' || s[pos] == '-') pos++;
        return matchUint(s, pos);
    }

public:
    bool isNumber(string s) {
        if (s.length() <= 0) return false;
        int pos = 0;
        bool flag = matchInt(s, pos);

        if (pos < s.length() && s[pos] == '.') {
            pos++;
        // 下面一行代码用||的原因：
        // 1. 小数可以没有整数部分，例如.123等于0.123；
        // 2. 小数点后面可以没有数字，例如233.等于233.0；
        // 3. 当然小数点前面和后面可以有数字，例如233.666
            flag = matchUint(s, pos) || flag;  // ! Note: lazy or
        }

        if (pos < s.length() && (s[pos] == 'e' || s[pos] == 'E')) {
            pos++;
        // 下面一行代码用&&的原因：
        // 1. 当e或E前面没有数字时，整个字符串不能表示数字，例如.e1、e1；
        // 2. 当e或E后面没有整数时，整个字符串不能表示数字，例如12e、12e+5.4
            flag = flag && matchInt(s, pos);
        }
        return pos == s.length() && flag;
    }
};

int main()
{
    Solution sol;
    cout << sol.isNumber("0") << endl;
    cout << sol.isNumber(".123") << endl;
    cout << sol.isNumber("233.") << endl;
    cout << sol.isNumber("12e+5.4") << endl;
    cout << sol.isNumber("123.45e+6") << endl;
    return 0;
}