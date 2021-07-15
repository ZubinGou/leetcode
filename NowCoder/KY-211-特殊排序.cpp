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

const int MAX_N = 1e7;

int n;
int a[MAX_N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    cout << a[n - 1] << endl;
    for (int i = 0; i < n - 1; i++)
        cout << a[i] << " ";

    if (n == 1)
        cout << "-1";
    return 0;
}