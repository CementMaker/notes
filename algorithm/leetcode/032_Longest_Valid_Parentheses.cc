/*
Given a string containing just the characters '(' and ')',
find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()",
which has length = 4.
*/
#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int res = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || stk.empty() || s[stk.top()] == ')') {
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {
                    res = max(res, i + 1);
                } else {
                    res = max(res, i - stk.top());
                }
            }
        }
        return res;
    }

    int longestValidParentheses_DP(const string& s) {
        int size = s.size();
        int res = 0;

        vector<int> d(size, 0);
        for (int i = 1; i < size; ++i) {
            if (s[i] == ')') {
                int prev = i - 1 - d[i - 1];
                if (prev >= 0 && s[prev] == '(') {
                    d[i] = d[i - 1] + 2;
                    if (prev > 1) {
                        d[i] = d[i] + d[prev - 1];
                    }
                    res = max(res, d[i]);
                }
            }
        }
        return res;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    Solution sol;

    cout << sol.longestValidParentheses("(()") << endl;
    cout << "---------------------" << endl;
    cout << sol.longestValidParentheses(")()()") << endl;
    cout << "---------------------" << endl;
    cout << sol.longestValidParentheses("()()") << endl;

    return 0;
}
#endif
