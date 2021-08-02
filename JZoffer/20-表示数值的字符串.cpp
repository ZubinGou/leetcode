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
private:
    bool matchNum(string s, int &pos) {
        if (pos >= s.length() || !isdigit(s[pos])) return false;
        while (isdigit(s[pos])) pos++;
        return true;
    }
    bool matchE(string s, int &pos) {
        if (pos == s.length()) return true;
        if (s[pos] != 'e' && s[pos] != 'E') return false;
        pos++;  // match e / E
        if (s[pos] == '+' || s[pos] == '-') pos++;
        bool tail_num = matchNum(s, pos);
        return tail_num && pos == s.length();
    }

public:
    bool isNumber(string s) {
        if (s.length() <= 0) return false;
        int pos = 0;
        if (s[0] == '+' || s[0] == '-')
            pos++;
        if (isdigit(s[pos])) {
            bool num = matchNum(s, pos);
            if (s[pos] == '.') {
                pos++;
                bool tail_num = matchNum(s, pos);
            }
            return num && matchE(s, pos);
        }
        else if (s[pos] == '.') {
            pos++;
            return matchNum(s, pos) && matchE(s, pos);
        }
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