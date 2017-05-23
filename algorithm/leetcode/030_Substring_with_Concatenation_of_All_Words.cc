/*
You are given a string, s, and a list of words, words, that are all of the same length.
Find all starting indices of substring(s) in s that is a concatenation of each word in words
exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0, 9].
(order does not matter).
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(const string& s, const vector<string>& words) {
        if (words.size() == 0) return {};
        unordered_map<string, int> freq;
        for (const string& w: words) {
            freq[w] += 1;
        }
        size_t word_len = words[0].size();

        vector<int> res;
        unordered_map<string, int> cnt;
        for (size_t i = 0; i < word_len; ++i) {
            cnt.clear();
            for (size_t j = i, left = i; j < s.size(); j += word_len) {
                string subword = s.substr(j, word_len);
                if (freq.find(subword) != freq.end()) {
                    ++cnt[subword];
                    while (cnt[subword] > freq[subword]) {
                        --cnt[s.substr(left, word_len)];
                        left += word_len;
                    }
                    if (j - left + word_len == word_len * words.size()) {
                        res.push_back(left);
                    }
                } else {
                    cnt.clear();
                    left = j + word_len;
                }
            }
        }
        return res;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    Solution sol;

    for (auto idx : sol.findSubstring("barfoothefoobarman", vector<string>({"foo", "bar"}))) {
        cout << idx << endl;
    }

    return 0;
}
#endif
