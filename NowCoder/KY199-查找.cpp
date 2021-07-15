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
int a[MAX_N];

bool binary_search(int n, int target)
{
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (high - low) / 2 + low;
        if (a[mid] == target)
            return true;
        else if (a[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

int main() {
    int n, m, target;
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    sort(a, a + n);

    cin >> m;
    while (m--) {
        cin >> target;
        if (binary_search(n, target))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}