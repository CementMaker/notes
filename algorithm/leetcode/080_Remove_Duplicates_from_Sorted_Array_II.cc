/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums
being 1, 1, 2, 2 and 3.

It doesn't matter what you leave beyond the new length.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int res = 1;

        int cnt = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                cnt = 0;
            }
            ++cnt;
            if (cnt <= 2) {
                nums[res++] = nums[i];
            }
        }
        return res;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    vector<int> nums({1, 1, 1, 2, 2, 3});

    cout << Solution().removeDuplicates(nums) << endl;
    for (auto n: nums) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
#endif
