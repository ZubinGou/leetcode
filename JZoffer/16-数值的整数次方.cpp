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
    double Power(double base, int exponent) {
        if (exponent < 0) return 1 / base * Power(1 / base, -(exponent + 1)); //  防止 INT_MIN 溢出
        if (exponent == 0) return 1;
        if (exponent == 1) return base;
        if (exponent == 2) return base * base;
        if (exponent % 2 == 0) return Power(Power(base, exponent / 2), 2);
        else return base * Power(Power(base, exponent / 2), 2);
    }
};

int main() {
    Solution sol;
    cout << sol.Power(10, 2) << endl;
    cout << sol.Power(10, -2) << endl;
    cout << sol.Power(10, -2147483648) << endl;
    return 0;
}