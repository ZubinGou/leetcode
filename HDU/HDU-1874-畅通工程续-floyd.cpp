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

const int MAX_N = 205;
const int INF = 1e9;

int adj[MAX_N][MAX_N];

void floyd(int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
}

int main() {
    int n, m;
    int a, b, x;
    int start, end;
    while (cin >> n >> m) {
        // init
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++)
                if (i == j)
                    adj[i][i] = 0;
                else
                    adj[i][j] = INF;
        
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> x;
            if (adj[a][b] > x)
                adj[a][b] = adj[b][a] = x;
        }
        floyd(n);
        cin >> start >> end;
        if (adj[start][end] == INF)
            cout << -1 << endl;
        else
            cout << adj[start][end] << endl;
    }

    return 0;
}