/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same
color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue
respectively.

Note:
You are not suppose to use the library's sort function for this problem.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        for (int j = 0; j <= 2; ++j) {
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] == j) {
                    swap(nums[i], nums[left]);
                    ++left;
                }
            }
        }
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    vector<int> nums({0, 2, 1, 2, 2, 1, 0, 0, 2, 1});

    Solution().sortColors(nums);
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
#endif
