/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell,
where "adjacent" cells are those horizontally or vertically neighboring.
The same letter cell may not be used more than once.

For example,
Given board =

[
    ['A','B','C','E'],
    ['S','F','C','S'],
    ['A','D','E','E']
]

word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, const string& word) {
        if (board.size() == 0) return word.size() == 0;
        int row = board.size();
        int col = board[0].size();

        vector<vector<bool>> used(row, vector<bool>(col, false));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (search(board, used, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool search(vector<vector<char>>& board,
                vector<vector<bool>>& used,
                int r,
                int c,
                const string& word,
                int word_idx) {
        if (board[r][c] != word[word_idx]) {
            return false;
        }
        if (word_idx + 1 == word.size()) return true;

        used[r][c] = true;
        for (auto& move: _sc_move) {
            if (r + move.first < 0 || r + move.first >= board.size()) continue;
            if (c + move.second < 0 || c + move.second >= board[0].size()) continue;
            if (used[r + move.first][c + move.second] == true) continue;
            if (search(board, used, r + move.first, c + move.second, word, word_idx + 1)) {
                return true;
            }
        }
        used[r][c] = false;
        return false;
    }

private:
    static const vector<pair<int, int>> _sc_move;
};

const vector<pair<int, int>> Solution::_sc_move{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    vector<vector<char>> board_test{{'a'}};

    cout << Solution().exist(board, "ABCCED") << endl;
    cout << Solution().exist(board, "SEE") << endl;
    cout << Solution().exist(board, "ABCB") << endl;
    cout << Solution().exist(board_test, "a") << endl;
    return 0;
}
#endif
