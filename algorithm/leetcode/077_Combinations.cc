/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
    [2,4],
    [3,4],
    [2,3],
    [1,2],
    [1,3],
    [1,4],
]
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
#ifdef SIMPLE
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        int i = 0;
        vector<int> p(k, 0);
        while (i >= 0) {
            p[i]++;
            if (p[i] > n) --i;
            else if (i == k - 1) result.push_back(p);
            else {
                ++i;
                p[i] = p[i - 1];
            }
        }
        return result;
    }

#else

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;

        vector<int> comb;
        search(1, n, k, comb, res);

        return res;
    }

private:
    void search(int pos, int n, int length, vector<int>& comb, vector<vector<int>>& res) {
        if (length == 0) {
            res.push_back(comb);
            return;
        }
        for (int i = pos; i + length - 1 <= n; ++i) {
            comb.push_back(i);
            search(i + 1, n, length - 1, comb, res);
            comb.pop_back();
        }
    }
#endif
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    for (auto& comb: Solution().combine(4, 2)) {
        for (auto n: comb) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}
#endif
