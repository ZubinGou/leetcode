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
    double PowerUnsigned(double base, unsigned int exponent) {
        if (exponent == 0) return 1;
        if (exponent == 1) return base;
        double res = Power(base, exponent >> 1);
        res *= res;
        if (exponent & 0x1 == 1) 
            res *= base;
        return res;
    }

    double Power(double base, int exponent) {
        unsigned int unsigned_exp = (unsigned int) exponent;
        if (exponent < 0) return PowerUnsigned(1 / base, -unsigned_exp);
        else return PowerUnsigned(base, unsigned_exp);
    }
};

int main() {
    Solution sol;
    cout << sol.Power(10, 2) << endl;
    cout << sol.Power(10, -2) << endl;
    cout << sol.Power(10, -2147483648) << endl;
    // cout << -(unsigned int)(-1) << endl;
    // cout << (unsigned int)(INT_MIN) << endl;
    // cout << UINT32_MAX << endl;
    return 0;
}