/*
Given an array of non-negative integers,
you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2.
(Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int pos = 0;
        int next_step = nums[0];
        for (int i = 0; i < nums.size(); ++i) { // maximum steps
            if (pos + 1 >= nums.size()) {
                return i;
            }

            int adjust_step = 0;
            for (int j = 1; j <= next_step; ++j) {
                adjust_step = max(adjust_step, nums[pos + j] - (next_step - j));
            }
            pos += next_step;
            next_step = adjust_step;
        }
        return nums.size() - 1;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    Solution sol;
    vector<int> nums{2, 3, 1, 1, 4};

    cout << sol.jump(nums) << endl;

    return 0;
}
#endif
