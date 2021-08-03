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
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq; // 大小为 K 的小顶堆
        for (auto x : nums) {
            if (pq.size() < k || x >= pq.top())  // 堆满后只送入大于堆顶的元素
                pq.push(x);
            if (pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};

int main()
{

    return 0;
}