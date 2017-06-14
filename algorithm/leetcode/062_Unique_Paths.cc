/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach
the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0) dp[i][j] += dp[i - 1][j];
                if (j > 0) dp[i][j] += dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    cout << Solution().uniquePaths(1, 1) << endl;
    cout << Solution().uniquePaths(2, 2) << endl;
    cout << Solution().uniquePaths(3, 2) << endl;

    return 0;
}
#endif
