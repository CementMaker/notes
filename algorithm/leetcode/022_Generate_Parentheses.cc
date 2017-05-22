/*
Given n pairs of parentheses, write a function to generate all combinations
of well-formed parentheses.

For example, given n = 3, a solution set is:

[
    "((()))",
    "(()())",
    "(())()",
    "()(())",
    "()()()"
]
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string parenthese(n * 2, ' ');

        dfs(0, 0, n, parenthese, res);
        return res;
    }
private:
    void dfs(int left, int right, int n, string& parenthese, vector<string>& res) {
        if (left == n && right == n) {
            res.push_back(parenthese);
            return;
        }

        if (left <= right) {
            parenthese[left + right] = '(';
            dfs(left + 1, right, n, parenthese, res);

        } else {
            parenthese[left + right] = ')';
            dfs(left, right + 1, n, parenthese, res);

            if (left < n) {
                parenthese[left + right] = '(';
                dfs(left + 1, right, n, parenthese, res);
            }
        }
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    Solution sol;

    vector<string> res = sol.generateParenthesis(3);
    for (size_t i = 0; i < res.size(); ++i) {
        cout << res[i] << endl;
    }
    return 0;
}
#endif
