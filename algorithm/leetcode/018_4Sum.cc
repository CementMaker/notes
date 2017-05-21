/*
Given an array S of n integers, are there elements a, b, c, and d in S such that
a + b + c + d = target?

Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
    [-1,  0, 0, 1],
    [-2, -1, 1, 2],
    [-2,  0, 0, 2]
]
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() <= 3) return res;

        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size() - 3; ++i) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;

            for (size_t j = i + 1; j < nums.size() - 2; ++j) {
                if (j != i + 1 && nums[j] == nums[j - 1]) continue;
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) continue;
                if (nums[i] + nums[j] + nums[nums.size() - 2] + nums[nums.size() - 1] < target) {
                    continue;
                }
                size_t left = j + 1;
                size_t right = nums.size() - 1;
                while (left < right) {
                    if (nums[i] + nums[j] + nums[left] + nums[right] == target) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        ++left;
                        --right;
                        while (left < right && nums[left] == nums[left - 1]) ++left;
                        while (left < right && nums[right] == nums[right + 1]) --right;
                    } else if (nums[i] + nums[j] + nums[left] + nums[right] < target) {
                        ++left;
                    } else {
                        --right;
                    }
                }
            }
        }
        return res;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    Solution sol;

    vector<int> nums = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> res = sol.fourSum(nums, 0);
    for (auto it = res.begin(); it != res.end(); ++it) {
        for (auto nit = it->begin(); nit != it->end(); ++nit) {
            cout << *nit << " ";
        }
        cout << endl;
    }
    return 0;
}
#endif
