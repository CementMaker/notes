/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
    [2],
    [1],
    [1,2,2],
    [2,2],
    [1,2],
    []
]
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<pair<int, int>> num2cnt;
        for (int i = 0; i < nums.size(); ++i) {
            if (num2cnt.size() == 0 || num2cnt[num2cnt.size() - 1].first != nums[i]) {
                num2cnt.push_back(make_pair(nums[i], 0));
            }
            num2cnt[num2cnt.size() - 1].second += 1;
        }

        vector<vector<int>> res;
        vector<int> subset;
        dfs(num2cnt, res, subset, 0);
        return res;
    }

private:
    void dfs(vector<pair<int, int>>& num2cnt,
             vector<vector<int>>& res,
             vector<int>& subset,
             int pos) {
        if (pos >= num2cnt.size()) {
            res.push_back(subset);
            return;
        }

        for (int i = 0; i <= num2cnt[pos].second; ++i) {
            if (i > 0) subset.push_back(num2cnt[pos].first);
            dfs(num2cnt, res, subset, pos + 1);
        }
        for (int i = 1; i <= num2cnt[pos].second; ++i) {
            subset.pop_back();
        }
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    vector<int> nums{1, 2, 2};

    for (auto& subset: Solution().subsetsWithDup(nums)) {
        for (auto& n: subset) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}
#endif
