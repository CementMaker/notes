/*
Given a collection of numbers that might contain duplicates,
return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
    [1,1,2],
    [1,2,1],
    [2,1,1]
]
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
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
    vector<int> nums{1, 1, 2};

    for (auto& res_vect: sol.permuteUnique(nums)) {
        for (auto n: res_vect) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}
#endif
