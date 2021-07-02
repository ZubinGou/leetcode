#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void dfs(string cur, int k, int n) {
	if (k == n)
		cout << cur << endl;
	else {
		for (int i = k; i < n; i++) {
			swap(cur[i], cur[k]);
			dfs(cur, k + 1, n);
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