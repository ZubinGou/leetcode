#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;


int get_max_power(int n) {
    int max_power = 0;
    int now = 1;
    while (now <= n) {
        max_power++;
        now *= 2;
    }
    return max_power - 1;
}

void recurse(int n) {
    int max_power = get_max_power(n);
    if (max_power == 0)
        cout << "2(0)";
    else if (max_power == 1)
        cout << "2";
    else if (max_power == 2)
        cout << "2(2)";
    else {
        cout << "2(";
        recurse(max_power);
        cout << ")";
    }
    int new_n = n - pow(2, max_power);
    if (new_n != 0) {
        cout << "+";
        recurse(new_n);
    }
}

int main() {
    int n;
    cin >> n;
    recurse(n);
    return 0;
}