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
    int n, now;
    while (cin >> n) {
        priority_queue<int, vector<int>, greater<int> > pq;  // 最小堆
        int res = 0;
        for (int i = 0; i < n; i++) {
            cin >> now;
            pq.push(now);
        }
        // huffman
        while (pq.size() > 1) {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            int c = a + b;
            pq.push(c);
            res += c;
        }
        cout << res << endl;
    }

    return 0;
}