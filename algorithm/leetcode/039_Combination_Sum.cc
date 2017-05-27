/*
Given a set of candidate numbers (C) (without duplicates) and a target number (T),
find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.

For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
    [7],
    [2, 2, 3]
]
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> sol;
        dfs(candidates, 0, target, res, sol);
        return res;
    }

private:
    void dfs(const vector<int>& candidates, int pos, int target, vector<vector<int>>& res,
                                                                 vector<int>& sol) {
        if (target == 0) {
            res.push_back(sol);
            return;
        }
        if (pos >= candidates.size()) return;

        for (int i = 0; i * candidates[pos] <= target; ++i) {
            if (i > 0) sol.push_back(candidates[pos]);
            dfs(candidates, pos + 1, target - i * candidates[pos], res, sol);
        }

        for (int i = 1; i * candidates[pos] <= target; ++i) {
            sol.pop_back();
        }
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    Solution sol;

    vector<int> candidates{2, 3, 6, 7};
    for (auto& res_vect: sol.combinationSum(candidates, 7)) {
        for (auto num: res_vect) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
#endif
