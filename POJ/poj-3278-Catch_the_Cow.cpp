#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
// #include <tr1/unordered_map>
// #include <<boost/tr1/unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

const int MAXN = 100001;

int n, k;
queue<pair<int, int>> q;
vector<bool> visited(MAXN, false);

void check_push(int pos, int step) {
    if (pos >= 0 && pos < MAXN && !visited[pos]) { // !! 从0开始
        q.push(make_pair(pos, step));
        visited[pos] = true;
    }
}

int bfs(int n, int k) {
    // n -> k
    q.push(make_pair(n, 0));
    visited[n] = true;
    while (!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();
        int pos = now.first, step = now.second;
        // cout << pos << " " << step << endl;
        if (pos == k)
            return step;
        check_push(pos - 1, step + 1);
        check_push(pos + 1, step + 1);
        check_push(pos * 2, step + 1);
    } 
}

int main() {
    cin >> n >> k;
    cout << bfs(n, k) << endl;
    return 0;
}