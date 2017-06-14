/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right
which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

#ifdef SIMPLE
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        int m = grid.size(); 
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) dp[i][j] = grid[i][j];
                else if (i == 0) dp[i][j] = dp[i][j - 1] + grid[i][j];
                else if (j == 0) dp[i][j] = dp[i - 1][j] + grid[i][j];
                else dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }

#else

    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        int m = grid.size(); 
        int n = grid[0].size();

        vector<int> dp(n, std::numeric_limits<int>::max());

        dp[0] = 0;
        for (int i = 0; i < m; ++i) {
            dp[0] += grid[i][0];
            for (int j = 1; j < n; ++j) {
                dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
            }
        }
        return dp[n - 1];
    }

#endif
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    vector<vector<int>> grid({{1, 3, 1},
                              {1, 5, 1},
                              {4, 2, 1}});
    cout << Solution().minPathSum(grid) << endl;

    return 0;
}
#endif
