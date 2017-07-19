/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return;

        int m = matrix.size();
        int n = matrix[0].size();
        if (n == 0) return;

        bool frz = false;
        bool fcz = false;
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (matrix[row][col] != 0) continue;
                if (row == 0) frz = true;
                if (col == 0) fcz = true;
                matrix[row][0] = 0;
                matrix[0][col] = 0;
            }
        }

        for (int row = 1; row < m; ++row) {
            for (int col = 1; col < n; ++col) {
                if (matrix[row][0] == 0 || matrix[0][col] == 0) {
                    matrix[row][col] = 0;
                }
            }
        }
        if (frz) for (int col = 0; col < n; ++col) matrix[0][col] = 0;
        if (fcz) for (int row = 0; row < m; ++row) matrix[row][0] = 0;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    vector<vector<int>> matrix({{0, 0, 0, 5},
                                {4, 3, 1, 4},
                                {0, 1, 1, 4},
                                {1, 2, 1, 3},
                                {0, 0, 1, 1}});

    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "-----------------------------------" << endl;
    Solution().setZeroes(matrix);
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
#endif
