/*
Given an array of non-negative integers, you are initially positioned at the first index
of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 0) return true;
        int pos = 0;
        int next_step = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            if (pos + 1 >= nums.size()) return true;

            int adjust_step = 0;
            for (int j = 1; j <= next_step; ++j) {
                adjust_step = max(adjust_step, nums[pos + j] - (next_step - j));
            }
            pos += next_step;
            next_step = adjust_step;
        }
        return false;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    vector<int> nums{2, 3, 1, 1, 4};
    cout << Solution().canJump(nums) << endl;

    nums = {3, 2, 1, 0, 4};
    cout << Solution().canJump(nums) << endl;

    return 0;
}
#endif
