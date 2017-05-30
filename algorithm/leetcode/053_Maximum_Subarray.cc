/*
Find the contiguous subarray within an array (containing at least one number)
which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the
divide and conquer approach, which is more subtle.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];

        int sum = 0;
        for (auto n: nums) {
            sum += n;
            res = max(res, sum);
            if (sum < 0) sum = 0;
        }
        return res;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << Solution().maxSubArray(nums) << endl;

    return 0;
}
#endif
