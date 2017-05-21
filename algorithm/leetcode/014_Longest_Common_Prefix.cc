/* Write a function to find the longest common prefix string amongst an array of strings.  */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";

        size_t len = strs[0].size();
        for (size_t i = 0; i < strs[0].size(); ++i) {
            size_t j = 0;
            while (j < strs.size()) {
                if (i >= strs[j].size() || strs[j][i] != strs[0][i]) {
                    break;
                }
                ++j;
            }
            if (j < strs.size()) {
                len = i;
                break;
            }
        }
        return strs[0].substr(0, len);
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    Solution sol;

    vector<string> strs = {"a", "b"};

    cout << "[" << sol.longestCommonPrefix(strs) << "]" << endl;
    return 0;
}
#endif
