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
*/

class Solution
{
private:
    int findMinSequential(vector<int> &nums, int left, int right)
    {
        int res = INT_MAX;
        for (int i = left; i <= right; i++)
            res = min(res, nums[i]);
        return res;
    }

public:
    int findMin(vector<int> &nums)
    {
        if (nums.size() == 0)
            return -1;

        int i = 0, j = nums.size() - 1;
        while (i + 1 < j)
        {
            int mid = i + ((j - i) >> 1);
            if (nums[mid] == nums[i] && nums[mid] == nums[j]) // all equal
                return findMinSequential(nums, i, j);
            if (nums[mid] <= nums[j])
                j = mid;
            else
                i = mid;
        }
        return min(nums[i], nums[j]);
    }
};

int main()
{

    vector<int> nums = {1, 1, 1, 0, 1};
    Solution sol;
    cout << sol.findMin(nums) << endl;
    return 0;
}