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

/*
O(log(m + n))

TODO !! Some Bugs, can't pass below test case online:

[0,0,0,0,0]
[-1,0,0,0,0,0,1]

*/

class Solution {
private:
    double getKth(int* nums1, int* nums2, int m, int n, int k) {
        // let m <= n
        if (m > n) return getKth(nums2, nums1, n, m, k);
        if (m == 0) return nums2[k - 1];
        if (k == 1) return min(nums1[0], nums2[0]);

        int j = min(k / 2, n);
        int i = k - j;
        if (nums1[i - 1] > nums2[j - 1])
            return getKth(nums1, nums2 + j, m, n - j, k - j);
        else 
            return getKth(nums1 + i, nums2, m - i, n, k - i);
    }

    double findMedian(int* nums1, int* nums2, int m, int n) {
        int l = (m + n + 1) >> 1;
        int r = (m + n + 2) >> 1;
        return (getKth(nums1, nums2, m, n, l) + getKth(nums1, nums2, m, n, r)) / 2.0; 
    }
    
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int *pNums1 = m > 0 ? &nums1[0] : nullptr;
        int *pNums2 = n > 0 ? &nums2[0] : nullptr;
        return findMedian(pNums1, pNums2, m, n);
   }
};

int main()
{
    // vector<int> nums1 = {1, 2}; vector<int> nums2 = {3, 4};
    // vector<int> nums1 = {0, 0}; vector<int> nums2 = {0, 0};
    // vector<int> nums1 = {}; vector<int> nums2 = {1};
    vector<int> nums1 = {0, 0, 0, 0, 0}; vector<int> nums2 = {-1, 0, 0, 0, 0, 0, 1};

    Solution sol;
    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}