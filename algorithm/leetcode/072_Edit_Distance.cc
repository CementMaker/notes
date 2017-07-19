/*
Given two words word1 and word2, find the minimum number of steps required to convert
word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.size() == 0) return word2.size();
        if (word2.size() == 0) return word1.size();

        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, n));
        
        for (int i = 0; i <= m; ++i) dp[i][0] = i;
        for (int j = 0; j <= n; ++j) dp[0][j] = j;
        
        for (int j = 1; j <= n; ++j) {
            for (int i = 1; i <= m; ++i) {
                dp[i][j] = min(dp[i][j - 1] + 1, dp[i - 1][j] + 1); // min(a, b)
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + int(word1[i - 1] != word2[j - 1]));
            }
        }
        return dp[m][n];
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {

    return 0;
}
#endif
