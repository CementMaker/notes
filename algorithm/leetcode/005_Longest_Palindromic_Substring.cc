/*
Given a string s, find the longest palindromic substring in s.
You may assume that the maximum length of s is 1000.

Example:
    Input: "babad"
    Output: "bab"
    Note: "aba" is also a valid answer.

Example:
    Input: "cbbd"
    Output: "bb"
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
#ifdef MANACHERS
public:
    string longestPalindrome(string s) {
        string ss;
        for (size_t k = 0; k < s.size(); ++k) {
            ss.push_back('#');
            ss.push_back(s[k]);
        }
        ss.push_back('#');

        vector<int> p(ss.size(), 0);
        int mp = 0;
        int mr = 0;
        for (size_t k = 1; k < ss.size(); ++k) {
            if (k <= mr) {
                if (p[2 * mp - k] < mr - k) {
                    p[k] = p[2 * mp - k];
                } else {
                    p[k] = mr - k;
                }
            }

            while (k >= p[k] && k + p[k] < ss.size() && ss[k - p[k]] == ss[k + p[k]]) {
                ++p[k];
            }

            if (k + p[k] > mr) {
                mr = k + p[k];
                mp = k;
            }
        }
        int pos = max_element(p.begin(), p.end()) - p.begin();
        string ans;
        for (int k = pos - p[pos] + 2; k < pos + p[pos]; k += 2) {
            ans += ss[k];
        }
        return ans;
    }

#else
public:
    string longestPalindrome(string s) {
        string result;

        int cdist;
        for (int i = 0; i < s.size(); ++i) {
            cdist = 0;
            while (i >= cdist && i + cdist < s.size() && s[i - cdist] == s[i + cdist]) {
                ++cdist;
            }
            if (cdist * 2 - 1 > result.size()) {
                result = s.substr(i - cdist + 1, 2 * cdist - 1);
            }

            cdist = 0;
            while (i >= cdist && i + 1 + cdist < s.size() && s[i - cdist] == s[i + 1 + cdist]) {
                ++cdist;
            }
            if (cdist * 2 > result.size()) {
                result = s.substr(i - cdist + 1, cdist * 2);
            }
        }
        return result;
    }
#endif
};

#ifdef LOCAL
int main() {
    Solution sol;

    cout << sol.longestPalindrome("babad") << endl;
    cout << sol.longestPalindrome("cbbd") << endl;
    cout << sol.longestPalindrome("abcd") << endl;

    return 0;
}
#endif
