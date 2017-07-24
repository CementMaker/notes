/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Write a function to determine if a given target is in the array.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0) return false;
        int left = 0;
        int right = nums.size() - 1;
        int mid = -1;

        while (left < right) {
            mid = left + ((right - left) >> 1);
            if (nums[mid] == target) return true;

            if (nums[mid] > nums[right]) {
                if (nums[mid] > target && nums[left] <= target) right = mid;
                else left = mid + 1;

            } else if (nums[mid] < nums[right]) {
                if (nums[mid] < target && nums[right] >= target) left = mid + 1;
                else right = mid;

            } else {
                --right;
            }
        }
        return nums[left] == target ? true : false;
		/*
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (nums[mid] == target) return true;

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
        */
        return false;
    }
};

#ifdef LOCAL
int main(int argc, const char* str[]) {
    Solution sol;
    //               0  1  2  3  4  5  6
    vector<int> nums{1, 3, 1, 1, 1};

    cout << sol.search(nums, 3) << endl;
    cout << sol.search(nums, 1) << endl;
    cout << sol.search(nums, 4) << endl;
    return 0;
    cout << sol.search(nums, 2) << endl;

    nums = {3, 1};
    cout << sol.search(nums, 3) << endl;
    cout << sol.search(nums, 1) << endl;
    cout << sol.search(nums, 2) << endl;
    return 0;
}
#endif
