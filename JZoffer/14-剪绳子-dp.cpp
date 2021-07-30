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
greedy:
尽量拆成 3，因为 3 * 3 > 2 * 2 * 2
剩下拆成 2
*/

class Solution {
public:
    int maxProductAfterCutting(int length) {
        if (length <= 3) return max(0, length - 1);
        int res = 1;
        if (length % 3 == 2) res = 2;
        else if (length % 3 == 1) {
            res = 4;
            length -= 4;
        }
        while (length >= 3) {
            res *= 3;
            length -= 3;
        }
        return res;
    }
};

int main() {
    Solution sol;

    cout << sol.maxProductAfterCutting(0) << endl;
    cout << sol.maxProductAfterCutting(1) << endl;
    cout << sol.maxProductAfterCutting(2) << endl;
    cout << sol.maxProductAfterCutting(8) << endl;
    cout << sol.maxProductAfterCutting(10) << endl;
    return 0;
}