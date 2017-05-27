/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search.
If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = -1;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[left] <= nums[mid]) {
                if (target < nums[mid] && nums[left] <= target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    Solution sol;
    //               0  1  2  3  4  5  6
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};

    cout << sol.search(nums, 3) << endl;
    cout << sol.search(nums, 4) << endl;
    cout << sol.search(nums, 2) << endl;
    cout << sol.search(nums, 1) << endl;

    nums = {3, 1};
    cout << sol.search(nums, 3) << endl;
    cout << sol.search(nums, 1) << endl;
    cout << sol.search(nums, 2) << endl;
    return 0;
}
#endif
