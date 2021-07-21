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

const int MAX_N = 105;

struct Program {
    int start;
    int end;
};

bool cmp(Program a, Program b) {
    return a.end < b.end;
}

Program p[MAX_N];

int main() {
    int n;
    while (cin >> n) {
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
            cin >> p[i].start >> p[i].end;
        sort(p, p + n, cmp);
        
        int last_end = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (p[i].start >= last_end) {
                res++;
                last_end = p[i].end;
            }
        }
        cout << res << endl;
    }

    return 0;
}