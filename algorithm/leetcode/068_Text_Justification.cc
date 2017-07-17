/*
Given an array of words and a length L, format the text such that each line has exactly L
characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in
each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible.
If the number of spaces on a line do not divide evenly between words,
the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted
between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
    "This    is    an",
    "example  of text",
    "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;

        string line;
        int left = 0;
        int tot_len = -1;
        for (int i = 0; i < words.size(); ++i) {
            tot_len += 1 + words[i].size();
            if (tot_len > maxWidth) {
                tot_len -= words[i].size() + 1;
                int empty_space_cnt = (maxWidth - tot_len) + (i - left) - 1;
                line.clear();
                for (int j = left; j < i; ++j) {
                    line += words[j];
                    if (j == i - 1) break;
                    line += string((empty_space_cnt - j + left - 1) / (i - left - 1) + 1, ' ');
                }
                res.push_back(line + string(maxWidth - line.size(), ' '));

                left = i;
                tot_len = words[i].size();
            }
        }

        line.clear();
        for (int j = left; j < words.size(); ++j) {
            line += words[j];
            if (j + 1 < words.size()) {
                line.push_back(' ');
            }
        }
        if (left < words.size()) {
            res.push_back(line + string(maxWidth - line.size(), ' '));
        }
        return res;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    vector<string> words = {"Listen", "to", "many,", "speak", "to", "a", "few."};
    int maxWidth = 6;

    cout << "\"" << string(maxWidth, '+') << "\"" << endl;
    for (auto& line: Solution().fullJustify(words, maxWidth)) {
        cout << "\"" << line << "\"" << endl;
    }
    return 0;
}
#endif
