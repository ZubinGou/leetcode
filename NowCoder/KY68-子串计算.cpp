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


int main() {
    string str;
    while (cin >> str) {
        int n = str.length();
        map<string, int> count;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= n - i; j++) {
                string sub_str = str.substr(i, j);
                count[sub_str]++;
            }
        }

        for (auto p : count)
            if (p.second > 1)
                cout << p.first << " " << p.second << endl;
    }

    return 0;
}