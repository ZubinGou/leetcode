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
    int countRange(vector<int> &nums, int left, int right)
    {
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] >= left && nums[i] <= right)
                res++;
        return res;
    }

public:
    int duplicateInArray(vector<int> &nums)
    {
        int left = 1, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);
            int count_left = countRange(nums, left, mid);
            if (left == right)
            {
                if (count_left > 1)
                    return left;
                else
                    break;
            }
            if (count_left > mid - left + 1)
                right = mid;
            else
                left = mid + 1;
        }
        return -1;
    }
};

int main()
{
    vector<int> nums = {2, 3, 5, 4, 3, 2, 6, 7};
    // vector<int> nums = {52, 35, 51, 77, 19, 10, 27, 37, 54, 26, 75, 9, 71, 81, 76, 75, 21, 100, 54, 50, 87, 40, 21, 87, 18, 23, 58, 12, 17, 84, 11, 6, 91, 73, 57, 19, 85, 65, 36, 44, 40, 77, 33, 56, 27, 48, 77, 59, 8, 65, 77, 13, 9, 52, 53, 9, 77, 73, 85, 33, 31, 10, 84, 94, 4, 13, 82, 12, 91, 89, 93, 40, 42, -100, 85, 36, 20, 33, 13, 48, 38, 93, 30, 87, 47, 44, 29, 47, 33, 52, 36, 55, 20, 29, 68, 58, 64, 5, 15, 26};

    Solution sol;
    cout << sol.duplicateInArray(nums) << endl;

    return 0;
}
