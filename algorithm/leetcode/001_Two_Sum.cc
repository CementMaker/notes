/*
Given an array of integers, return indices of the two numbers such that they add up to a specific
target.
You may assume that each input would have exactly one solution, and you may not use the same
element twice.

Example:
    Given nums = [2, 7, 11, 15], target = 9,

    Because nums[0] + nums[1] = 2 + 7 = 9,
    return [0, 1].
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:

#ifdef HASH
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num2idx;
        for (int i = 0; i < nums.size(); ++i) {
            if (num2idx.find(target - nums[i]) != num2idx.end()) {
                return {num2idx[target - nums[i]], i};
            }
            num2idx[nums[i]] = i;
        }
        return {};
    }

#else
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() <= 1) {
            return {};
        }

        vector<int> idx_vect(nums.size());
        for (size_t i = 0; i < nums.size(); ++i) {
            idx_vect[i] = i;
        }
        // Time Complexity O(n*log(n))
        sort(idx_vect.begin(), idx_vect.end(), [&nums](int a, int b) {
            return nums[a] < nums[b];
        });

        int left = 0;
        int right = idx_vect.size() - 1;

        while (left < right) {
            if (nums[idx_vect[left]] + nums[idx_vect[right]] == target) {
                return {idx_vect[left], idx_vect[right]};
            } else if (nums[idx_vect[left]] + nums[idx_vect[right]] < target) {
                ++left;
            } else if (nums[idx_vect[left]] + nums[idx_vect[right]] > target) {
                --right;
            }
        }
        return {};
    }
#endif // END OF ifdef HASH
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    vector<int> nums = {11, 7, 2, 15};

    Solution sol;
    vector<int> result = sol.twoSum(nums, 9);

    for (size_t i = 0; i < result.size(); ++i) {
        cout << (i == 0 ? "" : "\t") << result[i];
    }
    cout << endl;

    return 0;
}
#endif
