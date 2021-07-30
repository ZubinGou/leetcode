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
二分法
https://www.acwing.com/solution/content/727/
*/

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size() - 1;
        if (n < 0)
            return -1;
        while (n > 0 && nums[n] == nums[0])  // !!
            n--;
        if (nums[n] >= nums[0])
            return nums[0];
        int l = 0, r = n;
        while (l < r)
        {
            int mid = l + r >> 1; // [l, mid], [mid + 1, r]
            if (nums[mid] < nums[0])
                r = mid;
            else
                l = mid + 1;
        }
        return nums[r];
    }
};

int main()
{
    vector<int> nums = {1, 1, 1, 0, 1};
    Solution sol;
    cout << sol.findMin(nums) << endl;
    return 0;
}