/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        vector<string> nseq(1, "1");
        int cnt = 0;
        string nth;
        for (int i = 1; i < n; ++i) {
            nth = "";
            cnt = 0;
            for (int j = 0; j < nseq[i - 1].size(); ++j) {
                ++cnt;
                if (j + 1 == nseq[i - 1].size() || nseq[i - 1][j] != nseq[i - 1][j + 1]) {
                    nth.append(std::to_string(cnt));
                    nth.append(1, nseq[i - 1][j]);
                    cnt = 0;
                }
            }
            nseq.push_back(nth);
        }
        return nseq[n - 1];
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    Solution sol;

    for (int i = 1; i <= 10; ++i) {
        cout << i << " => " << sol.countAndSay(i) << endl;
    }

    return 0;
}
#endif
