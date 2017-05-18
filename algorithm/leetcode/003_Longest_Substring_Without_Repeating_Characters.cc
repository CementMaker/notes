/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3.

Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last_idx(256, -1);
        int max_len = 0;
        int left = 0;

        for (int i = 0; i < s.size(); ++i) {
            left = max(last_idx[static_cast<uint8_t>(s[i])] + 1, left);
            max_len = max(max_len, i - left + 1);
            last_idx[static_cast<uint8_t>(s[i])] = i;
        }
        return max_len;
    }
};

#ifdef LOCAL
int main(int argc, const char*argv[]) {
    Solution sol;

    cout << sol.lengthOfLongestSubstring("pwwkew") << endl;

    return 0;
}
#endif
