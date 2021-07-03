#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>  // can't compile on poj
#include <algorithm>
#include <climits>

using namespace std;

struct Code
{
    string s;
    int step;
    Code(string s, int step) : s(s), step(step){};
};

void bfs(string s) {
    unordered_map<string, bool> visited;
    queue<Code> q;
    q.push(Code(s, 0));
    
    while (!q.empty()) {
        Code code = q.front();
        q.pop();
        string str = code.s;
        if (str.find("2012") != string::npos) {
            cout << code.step << endl;
            return;
        }

        for (int i = 0; i < str.length() - 1; i++) {
            swap(str[i], str[i + 1]);
            if (!visited[str]) {
                q.push(Code(str, code.step + 1));
                visited[str] = true;
            }
            swap(str[i], str[i + 1]);
        }
    }
    cout << -1 << endl;
}

int main()
{
    int n;
    string s;
    while (cin >> n >> s)
        bfs(s);
    return 0;
}