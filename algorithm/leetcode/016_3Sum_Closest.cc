/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given
number, target. Return the sum of the three integers.

You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() <= 2) return 0;
        int64_t res = nums[0] + nums[1] + nums[2];

        sort(nums.begin(), nums.end());
        int trip_sum = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            size_t left = i + 1; 
            size_t right = nums.size() - 1;

            while (left < right) {
                trip_sum = nums[i] + nums[left] + nums[right];
                if (abs(trip_sum - target) < abs(res - target)) {
                    res = trip_sum;
                }

                if (trip_sum > target) {
                    //binary search `right' value
                    //lower_bound(nums.begin(), nums.end(), target - nums[i] - nums[left]);
                    --right;
                } else{
                    ++left;
                }
            }
        }
        return res;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    Solution sol;

    vector<int> nums = {-1, 2, 1, -4};
    cout << sol.threeSumClosest(nums, 1) << endl;

    return 0;
}
#endif
