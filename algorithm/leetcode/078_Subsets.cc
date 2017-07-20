/*
Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
    [3],
    [1],
    [2],
    [1,2,3],
    [1,3],
    [2,3],
    [1,2],
    []
]
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;

        int limits = 1 << nums.size();
        for (int i = 0; i < limits; ++i) {
            subset.clear();
            for (int j = 0; j < nums.size(); ++j) {
                if ((i & (1 << j)) == 0) {
                    subset.push_back(nums[j]);
                }
            }
            res.push_back(subset);
        }
        return res;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    vector<int> nums({1, 2, 3});

    for (auto subset: Solution().subsets(nums)) {
        for (auto n: subset) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}
#endif
