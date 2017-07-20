/*
Given a string S and a string T, find the minimum window in S which
will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be
only one unique minimum window in S.
*/
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> require;
        for (auto c: t) {
            require[c] += 1;
        }

        int res_start = 0;
        int res_end = 0;

        int missing = t.size();
        int start = 0;
        for (int i = 0; i < s.size(); ++i) {
            missing -= require[s[i]] > 0;
            --require[s[i]];

            if (missing <= 0) {
                while (start < i && require[s[start]] < 0) {
                    require[s[start]] += 1;
                    ++start;
                }
                if (res_end <= 0 || i - start + 1 <= res_end - res_start) {
                    res_start = start;
                    res_end = i + 1;
                }
            }
        }
        return s.substr(res_start, res_end - res_start);
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    cout << Solution().minWindow("ADOBECODEBANC", "ABC") << endl;
    cout << Solution().minWindow("a", "aa") << endl;
    cout << Solution().minWindow("ab", "a") << endl;
    return 0;
}
#endif
