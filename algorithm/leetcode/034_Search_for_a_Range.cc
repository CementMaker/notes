/*
Given an array of integers sorted in ascending order,
find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
    Given [5, 7, 7, 8, 8, 10] and target value 8,
    return [3, 4].
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lower_it = lower_bound(nums.begin(), nums.end(), target);
        auto upper_it = upper_bound(nums.begin(), nums.end(), target);

        if (lower_it == nums.end() || *lower_it > target) {
            return {-1, -1};
        }
        int left = std::distance(nums.begin(), lower_it);
        int right = std::distance(nums.begin(), upper_it) - 1;
        return {left, right};
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    Solution sol;
    vector<int> nums{5, 7, 7, 8, 8, 10};

    for (auto idx: sol.searchRange(nums, 8)) {
        cout << idx << endl;
    }
    return 0;
}
#endif
