/*
Given a collection of candidate numbers (C) and a target number (T),
find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.

For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
A solution set is: 
[
    [1, 7],
    [1, 2, 5],
    [2, 6],
    [1, 1, 6]
]
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>

using namespace std;

class Solution {
public:
    // Another solution: 
    // count frequency first, and use enumerate method, which do not need using set data strucute.
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        set<vector<int>> res;
        vector<int> sol;
        dfs(candidates, 0, target, res, sol);
        return vector<vector<int>>(res.begin(), res.end());
    }

private:
    void dfs(const vector<int>& candidates, int pos, int target, set<vector<int>>& res,
                                                                 vector<int>& sol) {
        if (target < 0) return;
        if (target == 0) {
            res.insert(sol);
            return;
        }
        if (pos >= candidates.size()) return;
        dfs(candidates, pos + 1, target, res, sol);

        sol.push_back(candidates[pos]);
        dfs(candidates, pos + 1, target - candidates[pos], res, sol);
        sol.pop_back();
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    Solution sol;
    vector<int> candidates{10, 1, 2, 7, 6, 1, 5};

    for (auto& res_vect: sol.combinationSum2(candidates, 8)) {
        for (auto num: res_vect) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
#endif
