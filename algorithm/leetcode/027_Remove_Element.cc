/*
Given an array and a value, remove all instances of that value in place and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:
Given input array nums = [3,2,2,3], val = 3

Your function should return length = 2, with the first two elements of nums being 2.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = 0;
        for (auto n : nums) {
            if (n != val) {
                nums[len++] = n;
            }
        }
        return len;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    vector<int> nums({3, 2, 2, 3});

    Solution sol;
    cout << "len = " << sol.removeElement(nums, 3) << endl;
    for (auto n : nums) {
        cout << n << endl;
    }
    return 0;
}
#endif
