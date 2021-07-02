#include <string>
#include <cctype>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        long long l = 0;
        int res;
        int sign = 0;
        bool has_digit = false;
        for (auto c : s) {
            if (c == ' ' && !has_digit && !sign) {
                continue;
            }
            else if (c == '-' && !has_digit && !sign) {
                sign = -1;
            }
            else if (c == '+' && !has_digit && !sign) {
                sign = 1;
            }
            else if (isdigit(c)) {
                has_digit = true;
                l = l * 10 + c - '0';
                if ((sign == 0 || sign == 1) && l > INT_MAX) return INT_MAX;
                else if (sign < 0 && l * sign < INT_MIN) return INT_MIN;
            }
            else 
                break; 
            cout << l << " " << sign << endl;
        }
        if (sign == 0) sign = 1;
        res = (int)l * sign;
        return res;
    }
};


int main() {
    Solution sol;
    int res = sol.myAtoi("21474836460");
    cout << res;
}