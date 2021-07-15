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
解法：
1. 直接sort，然后后向打印 + 前向打印
2. 写cmp：奇数在前，偶数在后，奇数大到小、偶数小到大
3. 排序两次
*/

bool cmp(int a, int b) {
    if ((a - b) % 2)  // 异号
        return a & 1;
    else
        return (a < b) ^ (a & 1);
}

int main() {
    int i = 0;
    int n = 10;
    int a[n];
    while (cin >> a[i++]) {
        if (i % n == 0) {
            sort(a, a + n, cmp);
            for (int j = 0; j < n; j++)
                cout << a[j] << " ";
            cout << endl;
        }
    }
    return 0;
}