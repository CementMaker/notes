/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // Using dfs is another feasible method.
    bool isMatch(const string& s, const string& p) {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= p.size(); ++i) {
            dp[0][i] = (p[i - 1] == '*') && dp[0][i - 1];
        }

        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 1; j <= p.size(); ++j) {
                if (p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];

                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j - 1] || dp[i - 1][j];

                } else {
                    dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1]);
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    Solution sol;

    cout << sol.isMatch("aa","a") << " => " << false << endl;
    cout << sol.isMatch("aa","aa") << " => " <<  true << endl;
    cout << sol.isMatch("aaa","aa") << " => " << false << endl;
    cout << sol.isMatch("aa", "*") << " => " << true << endl;
    cout << sol.isMatch("aa", "a*") << " => " << true << endl;
    cout << sol.isMatch("ab", "?*") << " => " <<  true << endl;
    cout << sol.isMatch("aab", "c*a*b") << " => " << false << endl;

    return 0;
}
#endif
