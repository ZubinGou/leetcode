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


int main() {
    int a;
    while (cin >> a) {
        int res_min = 0, res_max = 0;
        if (a % 2 == 0) {
            res_min = a / 4 + (a % 4) / 2;
            res_max = a / 2;
        }
        cout << res_min << " " << res_max << endl;
    }

    return 0;
}