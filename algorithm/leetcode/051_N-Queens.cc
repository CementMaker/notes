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

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> solution(n, string(n, '.'));

        dfs(0, n, solution, res);
        return res;
    }

private:
    void dfs(int row, int n, vector<string>& solution, vector<vector<string>>& res) {
        if (row == n) {
            res.push_back(solution);
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

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    for (auto& puzzle: Solution().solveNQueens(8)) {
        cout << "-------------------" << endl;
        for (auto& row: puzzle) {
            for (auto c: row) {
                cout << c << " ";
            }
            cout << endl;
        }
        cout << "-------------------" << endl;
    }
    return 0;
}
#endif
