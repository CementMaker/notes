/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable.
Only the filled cells need to be validated.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.size() != 9 || board.size() != board[0].size()) return false;

        vector<uint64_t> row(9, 0);
        vector<uint64_t> col(9, 0);
        vector<uint64_t> cell(9, 0);

        int number;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                number = board[i][j] - '0';

                if ((row[i] >> (number - 1)) & 1) {
                    return false;
                } else {
                    row[i] |= 1ull << (number - 1);
                }

                if ((col[j] >> (number - 1)) & 1) {
                    return false;
                } else {
                    col[j] |= 1ull << (number - 1);
                }

                if ((cell[i / 3 * 3 + j / 3] >> (number - 1)) & 1) {
                    return false;
                } else {
                    cell[i / 3 * 3 + j / 3] |= 1ull << (number - 1);
                }
            }
        }
        return true;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    Solution sol;

    vector<vector<char>> board;
    const char* matrix[9] = {
            "..4...63.",
            ".........",
            "5......9.",
            "...56....",
            "4.3.....1",
            "...7.....",
            "...5.....",
            ".........",
            "........."
    };

    for (int i = 0; i < sizeof(matrix) / sizeof(matrix[0]); ++i) {
        board.push_back(vector<char>(9, '\0'));
        for (int j = 0; matrix[i][j] != '\0'; ++j) {
            board[i][j] = matrix[i][j];
        }
    }
    cout << sol.isValidSudoku(board) << endl;
    return 0;
}
#endif
