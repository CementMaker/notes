/*
The n-queens puzzle is the problem of placing n queens on an n ×n chessboard
such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement,
where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
    [".Q..",  // Solution 1
     "...Q",
     "Q...",
     "..Q."],

    ["..Q.",  // Solution 2
     "Q...",
     "...Q",
     ".Q.."]
    ]
]
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#ifdef SIMPLE
class Solution {
public:
    int totalNQueens(int n) {
        vector<string> solution(n, string(n, '.'));

        int res = 0;
        dfs(0, n, solution, res);
        return res;
    }

private:
    void dfs(int row, int n, vector<string>& solution, int& res) {
        if (row == n) {
            ++res;
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (!can_place(solution, n, row, i)) continue;
            solution[row][i] = 'Q';
            dfs(row + 1, n, solution, res);
            solution[row][i] = '.';
        }
    }

    bool can_place(vector<string>& solution, int n, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (solution[i][col] == 'Q') return false;
            if (col - row + i >= 0 && solution[i][col - row + i] == 'Q') return false;
            if (col + row - i < n && solution[i][col + row - i] == 'Q') return false;
        }
        return true;
    }
};

#else

class Solution {
public:
    int totalNQueens(int n) {
        int upperlim = (1 << n) - 1;
        int ans = 0;
        
        for (int i = 0; i < n / 2; ++i) {
            dfs(1 << i, 1 << (i + 1), 1 << (i - 1), upperlim, ans);
        }
        ans *= 2;
        if (n & 1) {
            n >>= 1;
            dfs(1 << n, 1 << (n + 1), 1 << (n - 1), upperlim, ans);
        }
        return ans;
    }

private:
    void dfs(int row, int ld, int rd, int upperlim, int &ans) {
        if (row == upperlim) {
            ++ans;
            return;
        }
        int pos = upperlim & ~(row | ld | rd);
        while (pos != 0) {
            int p = pos & -pos;
            dfs(row | p, (ld | p ) << 1, (rd | p) >> 1, upperlim, ans);
            pos -= p;
        }
    }
};
#endif


#ifdef LOCAL
int main(int argc, const char* argv[]) {
    for (int i = 4; i <= 10; ++i) {
        cout << i << " => " << Solution().totalNQueens(i) << endl;
    }
    return 0;
}
#endif
