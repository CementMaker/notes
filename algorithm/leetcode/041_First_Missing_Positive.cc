/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int j = nums[i] - 1;
            while (0 <= j && j < nums.size() && nums[j] != j + 1) {
                int t = nums[j];
                nums[j] = j + 1;
                j = t - 1;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    Solution sol;

    vector<int> nums = {1, 2, 0};
    cout << sol.firstMissingPositive(nums) << endl;

    nums = {3, 4, -1, 1};
    cout << sol.firstMissingPositive(nums) << endl;

    nums = {0, -1, 3, 1};
    cout << sol.firstMissingPositive(nums) << endl;

    return 0;
}
#endif
