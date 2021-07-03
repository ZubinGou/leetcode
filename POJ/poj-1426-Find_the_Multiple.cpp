#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
// #include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

void bfs(int n) {
    queue<long long> q;
    q.push(1);
    while (!q.empty()) {
        long long cur = q.front();
        q.pop();
        if (cur % n == 0) {
            printf("%lld\n", cur);
            return;
        }
        q.push(cur * 10);
        q.push(cur * 10 + 1);
    }
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0)
            break;
        bfs(n);
    }

    return 0;
}