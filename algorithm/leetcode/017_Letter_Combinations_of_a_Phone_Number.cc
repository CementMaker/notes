/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters is just like on the telephone buttons.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.size() == 0) return res;

        char lex[digits.size() + 1];
        dfs(digits, 0, res, lex);
        return res;
    }

private:
    void dfs(const string& digits, int pos, vector<string>& res, char* lex) {
        if (pos >= digits.size()) {
            lex[pos] = '\0';
            res.push_back(lex);
            return;
        }
        for (size_t i = 0; i < _m_mapping[digits[pos] - '2'].size(); ++i) {
            lex[pos] = _m_mapping[digits[pos] - '2'][i];
            dfs(digits, pos + 1, res, lex);
        }
    }

private:
    const vector<string> _m_mapping = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    Solution sol;

    vector<string> res = sol.letterCombinations("23");

    for (auto it = res.begin(); it != res.end(); ++it) {
        cout << *it << endl;
    }
    return 0;
}
#endif
