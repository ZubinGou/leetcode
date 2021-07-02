#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;


int main() {
    int m, n;
    while (cin >> m >> n) {
        if (m == 0) break;

        int res = 0;       
        int left = m, right = m;
        while (true) {
            if (left > n)
                break;
            else if (right >= n) {
                res += n - left + 1;
                break;
            }
            else
                res += right - left + 1;

            left = left * 2;
            right = right * 2 + 1;
        }
        cout << res;
    }

    return 0;
}