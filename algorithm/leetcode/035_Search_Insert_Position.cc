/*
Given a sorted array and a target value, return the index if the target is found.
If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return std::distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target));
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    Solution sol;
    vector<int> nums{1, 3, 5, 6};

    cout << sol.searchInsert(nums, 5) << endl;
    cout << sol.searchInsert(nums, 2) << endl;
    cout << sol.searchInsert(nums, 7) << endl;
    cout << sol.searchInsert(nums, 0) << endl;

    return 0;
}
#endif
