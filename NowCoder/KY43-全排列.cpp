#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void dfs(string cur, int k, int n) {
	if (k == n)
		cout << cur << endl;
	else {
		for (int i = k; i < n; i++) {
			string new_cur = cur;
			swap(new_cur[i], new_cur[k]);
			sort(new_cur.begin() + k + 1, new_cur.end());
			dfs(new_cur, k + 1, n);
		}
	}
}

int main() {
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	int n = s.length();
	dfs(s, 0, n);
}