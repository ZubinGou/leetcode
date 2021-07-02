#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

int recurse(int n, int k) {
    if (k <= n)
        return 1 + recurse(n, 2 * k) + recurse(n, 2 * k + 1);
    else 
        return 0;
}


int main() {
    int m, n;
    while (cin >> m >> n) {
        if (m == 0) break;
        cout << recurse(n, m);
    }
    return 0;
}