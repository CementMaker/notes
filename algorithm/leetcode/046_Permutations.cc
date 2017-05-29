/*
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
    [1,2,3],
    [1,3,2],
    [2,1,3],
    [2,3,1],
    [3,1,2],
    [3,2,1]
]
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());
        do {
            res.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return res;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    Solution sol;
    vector<int> nums{3, 1, 2};

    for (auto& res_vect : sol.permute(nums)) {
        for (auto n: res_vect) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}
#endif
