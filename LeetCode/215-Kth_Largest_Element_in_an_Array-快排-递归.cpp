#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
// #include <unordered_map>  // can't compile on poj
#include <algorithm>
#include <cstring>
#include <climits>
#include <ctime>

using namespace std;

class Solution {
private:
    int partition(vector<int>& nums, int left, int right) {
        // 双指针前移法
        int pivot = nums[right];
        int i = left;
        for (int j = left; j < right; j++) {
            if (nums[j] < pivot)
                swap(nums[i++], nums[j]);
        }
        swap(nums[i], nums[right]);
        return i;
    }

    int randomPartition(vector<int>& nums, int left, int right) {
        srand(time(NULL));
        int pivot = left + rand() % (right - left);
        swap(nums[pivot], nums[right]);
        return partition(nums, left, right);
    }

    int quicksort(vector<int>& nums, int left, int right, int k) {
        if (left == right) return nums[left];
        int pi = partition(nums, left, right);
        int right_count = right - pi;
        if (k == right_count + 1)
            return nums[pi];
        else if (k > right_count + 1)
            return quicksort(nums, left, pi - 1, k - (right_count + 1));
        else
            return quicksort(nums, pi + 1, right, k);
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        return quicksort(nums, 0, nums.size() - 1, k);
    }
};

int main()
{

    return 0;
}