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

map<string, string> dictionary;

int main() {
    string str;
    while (true) {
        getline(cin, str);
        if (str[0] == '@') break;
        int sep_pos = str.find("]");
        string curse = str.substr(0, sep_pos + 1);
        string function = str.substr(sep_pos + 2);
        dictionary[curse]  = function;
        dictionary[function] = curse;
    }
    int n;
    cin >> n;
    getchar();  // '\n'
    while (n--) {
        getline(cin, str);
        string res = dictionary[str];
        if (res == "") res = "what?";
        if (res[0] == '[') res = res.substr(1, res.length() - 2);
        cout << res << endl;
    }

    return 0;
}