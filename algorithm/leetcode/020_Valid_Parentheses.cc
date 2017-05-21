/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid
but "(]" and "([)]" are not.
*/
#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> sk;

        for (auto c: s) {
            if (c == '(' || c == '{' || c == '[') {
                sk.push(c);
            } else {
                if (sk.size() == 0 || (sk.top() == '(' && c != ')') ||
                                      (sk.top() == '[' && c != ']') ||
                                      (sk.top() == '{' && c != '}')) {
                    return false;
                }
                sk.pop();
            }
        }
        return sk.size() == 0;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    Solution sol;

    cout << sol.isValid("()[]{}") << endl;
    cout << sol.isValid("([)]{}") << endl;

    return 0;
}
#endif
