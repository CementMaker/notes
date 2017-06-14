/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
    [0,0,0],
    [0,1,0],
    [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0) return 0;

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        if (obstacleGrid[0][0] == 0) {
            dp[0][0] = 1;
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    if (i > 0) dp[i][j] += dp[i - 1][j];
                    if (j > 0) dp[i][j] += dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    vector<vector<int>> obstacleGrid({{0, 0, 0}, {0, 1, 0}, {0, 0, 0}});

    cout << Solution().uniquePathsWithObstacles(obstacleGrid) << endl;

    return 0;
}
#endif
