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
    int Fibonacci(int n) {
        int a = 0, b = 1, tmp;
        while (n--) {
            tmp = b;
            b = a + b;
            a = tmp;
        }
        return a;
    }
};

int main() {
    Solution sol;
    cout << sol.Fibonacci(0) << endl;
    cout << sol.Fibonacci(5) << endl;
    cout << sol.Fibonacci(10) << endl;

    return 0;
}