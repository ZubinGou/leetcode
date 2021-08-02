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

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int i = 0, j = 0, n = array.size();
        while (i < n && j < n) {
            for (     ; i < n && array[i] & 0x1 == 1; i++);
            for (j = i; j < n && array[j] & 0x1 == 0; j++);
            if (i < n && j < n)
                swap(array[i++], array[j]);
        } 
    }
};    

void printArray(vector<int> array) {
    for (auto x : array) cout << x << " ";
    cout << endl;
}

int main()
{
    Solution sol;
    vector<int> array = {1,2,3,4,5};
    sol.reOrderArray(array);
    printArray(array);
    return 0;
}