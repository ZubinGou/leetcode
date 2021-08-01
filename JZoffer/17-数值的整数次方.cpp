#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
// #include <unordered_map>  // can't compile on poj
#include <algorithm>
#include <cstring>
#include <string>
#include <climits>

using namespace std;

class Solution {
private:
    vector<int> res;
    const int MAX_N = 100;

    void print2Res(string str, int n) {
        int str_int = stoi(str.substr(0, n));
        if (str_int) {
            cout << str_int << endl;
            res.push_back(str_int);
        }
    }

    void permutation(string& str, int n, int pos) {
        if (pos >= n) {
            print2Res(str, n);
            return;
        }
        for (int i = 0; i <= 9; i++) {
            str[pos] = i + '0';
            permutation(str, n, pos + 1);
        }
    }

public:
    vector<int> printNumbers(int n) {
        if (n <= 0) return {};
        res.clear();
        string str(MAX_N, '0');
        permutation(str, n, 0);
        return res;
    }
};

int main() {
    Solution sol;
    // sol.printNumbers(0);
    sol.printNumbers(1);
    // sol.printNumbers(2);
    return 0;
}