#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
// #include <unordered_map>  // can't compile on poj
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX_M = 30;

int n, m, sum, avg;
int a[MAX_M];
bool visited[MAX_M];

/*********************************
 * 剪枝：
 * 1. 总长不整除4
 * 2. 最长棍长度大于边长
*********************************/

bool dfs(int step, int cur_len, int pos) {
    if (step == 3) {
        return true;
    }
    // else
    for (int i = pos; i < m; i++) {
        if (visited[i] || cur_len + a[i] > avg)
            continue;

        visited[i] = true;
        if (cur_len + a[i] == avg) { // next step
            if (dfs(step + 1, 0, 0))
                return true;
        }
        else if (cur_len + a[i] < avg) {
            if (dfs(step, cur_len + a[i], i + 1))
                return true;
        }

        visited[i] = false;
    }
    return false;
}


int main() {
    cin >> n;
    while (n--) {
        cin >> m;
        sum = 0;
        for (int i = 0; i < m; i++) {
            cin >> a[i];
            sum += a[i];
        }
        if (sum % 4 != 0) {
            cout << "no" << endl;
            continue;
        }
        sort(a, a + m, greater<int>());
        avg = sum / 4;
        if (a[0] > avg) {
            cout << "no" << endl;
            continue;
        }
        memset(visited, false, sizeof(visited));
        if (dfs(0, 0, 0))
            cout << "yes" << endl;
        else
            cout <<  "no" << endl;
    }

    return 0;
}