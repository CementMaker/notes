/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 

Return:
[
    ["ate", "eat","tea"],
    ["nat","tan"],
    ["bat"]
]

Note: All inputs will be in lower-case.
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;

        unordered_map<string, vector<string>> group;
        for (auto& str: strs) {
            string t(str);
            sort(t.begin(), t.end());
            group[t].push_back(str);
        }

        for (auto it = group.begin(); it != group.end(); ++it) {
            res.push_back(it->second);
        }
        return res;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    Solution sol;
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};

    for (auto& group: sol.groupAnagrams(strs)) {
        for (auto& str: group) {
            cout << str << "\t";
        }
        cout << endl;
    }
    return 0;
}
#endif
