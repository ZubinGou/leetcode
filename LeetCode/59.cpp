#include <string>
#include <cctype>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        int l = 0, r = n - 1, u = 1, d = n - 1;
        int k = 1;
        int i = 0, j = -1;
        vector<vector<int>> res(n, vector<int>(n));
        while (k <= n * n)
        {
            while (j < r && k <= n * n)
                res[i][++j] = k++;
            r--;
            while (i < d && k <= n * n)
                res[++i][j] = k++;
            d--;
            while (j > l && k <= n * n)
                res[i][--j] = k++;
            l++;
            while (i > u && k <= n * n)
                res[--i][j] = k++;
            u++;
        }
        return res;
    }
};

void printMat(vector<vector<int>> mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution sol;
    printMat(sol.generateMatrix(4), 4);
    return 0;
}