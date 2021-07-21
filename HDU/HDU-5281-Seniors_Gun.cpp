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
注意：本题卡 cin 输入，得用 scanf ;)
*/

const int MAX_N = 1e5 + 50;
long long a[MAX_N], b[MAX_N];

int main() {
    int T;
    int n, m;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
            scanf("%lld", &a[i]);

        for (int i = 0; i < m; i++)
            scanf("%lld", &b[i]);
        
        sort(a, a + n, greater<long long>());
        sort(b, b + m);
        long long res = 0;
        for (int i = 0; i < n && i < m; i++) {
            if (a[i] > b[i]) {
                res += a[i] - b[i];
            }
            else
                break;
        }
        printf("%lld\n", res);
     }

    return 0;
}