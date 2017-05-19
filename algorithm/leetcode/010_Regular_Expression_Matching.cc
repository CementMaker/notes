/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        dp[0][0] = true;
        for (int pi = 1; pi <= p.size(); ++pi) {
            dp[0][pi] = (p[pi - 1] == '*' && dp[0][pi - 2]);
        }

        for (int si = 1; si <= s.size(); ++si) {
            for (int pi = 1; pi <= p.size(); ++pi) {
                if (p[pi - 1] == '*') {
                    dp[si][pi] = dp[si-1][pi] && (p[pi - 2] == '.' || p[pi - 2] == s[si - 1]);
                    dp[si][pi] = dp[si][pi] || dp[si][pi - 2];
                } else {
                    dp[si][pi] = dp[si-1][pi-1] && (p[pi - 1] == '.' || p[pi - 1] == s[si - 1]);
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    Solution sol;

    cout << sol.isMatch("aa", "a") << "\t" << 0 << endl;      // false
    cout << sol.isMatch("aa", "aa") << "\t" << 1 << endl;     // true
    cout << sol.isMatch("aaa", "aa") << "\t" << 0 << endl;    // false
    cout << sol.isMatch("aa", "a*") << "\t" << 1 << endl;     // true
    cout << sol.isMatch("aa", ".*") << "\t" << 1 << endl;     // true
    cout << sol.isMatch("ab", ".*") << "\t" << 1 << endl;     // true
    cout << sol.isMatch("aab", "c*a*b") << "\t" << 1 << endl; // true

    return 0;
}
#endif
