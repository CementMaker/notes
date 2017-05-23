/*
Given a sorted array, remove the duplicates in place such that each element appear only once
and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2
respectively. It doesn't matter what you leave beyond the new length.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i + 1 == nums.size() || nums[i] != nums[i + 1]) {
                nums[len++] = nums[i];
            }
        }
        return len;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    vector<int> nums({1, 1, 2});
    Solution sol;

    cout << "len = " << sol.removeDuplicates(nums) << endl;
    for (auto k : nums) {
        cout << k << endl;
    }
    return 0;
}
#endif
