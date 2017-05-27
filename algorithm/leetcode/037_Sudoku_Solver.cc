/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board, 0, 0);
    }

private:
    bool dfs(vector<vector<char>>& board, int row, int col) {
        if (row >= 9) return true;

        if (board[row][col] != '.') {
            return dfs(board, row + col / 8, (col + 1) % 9);

        } else {
            bool valid = true;
            for (char c = '1'; c <= '9'; ++c) {
                valid = true;
                for (int i = 0; i < 9; ++i) {
                    if (i == row) continue;
                    if (board[i][col] == c) {
                        valid = false;
                        break;
                    }
                }
                if (!valid) continue;

                for (int i = 0; i < 9; ++i) {
                    if (i == col) continue;
                    if (board[row][i] == c) {
                        valid = false;
                        break;
                    }
                }
                if (!valid) continue;

                for (int i = 0; i < 9; ++i) {
                    if (row % 3 == i / 3 && col % 3 == i % 3) continue;
                    if (board[row / 3 * 3 + i / 3][col / 3 * 3 + i % 3] == c) {
                        valid = false;
                        break;
                    }
                }
                if (!valid) continue;
 
                board[row][col] = c;
                if (dfs(board, row + col / 8, (col + 1) % 9)) return true;
                board[row][col] = '.';
            }
            return false;
        }
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    Solution sol;
    const char* matrix[9] = {
        "53..7....",
        "6..195...",
        ".98....6.",
        "8...6...3",
        "4..8.3..1",
        "7...2...6",
        ".6....28.",
        "...419..5",
        "....8..79"
    };

    vector<vector<char>> board;
    for (int i = 0; i < sizeof(matrix) / sizeof(matrix[0]); ++i) {
        board.push_back(vector<char>(9, '\0'));
        for (int j = 0; matrix[i][j] != '\0'; ++j) {
            board[i][j] = matrix[i][j];
        }
    }
    cout << "----------------- BEFORE ----------------------" << endl;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "----------------- AFTER ----------------------" << endl;
    sol.solveSudoku(board);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "----------------------------------------------" << endl;
    return 0;
}
#endif
