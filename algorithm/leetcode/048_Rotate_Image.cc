/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return;
        int N = matrix.size();

        int t = 0;
        for (int i = 0; i < (N + 1) / 2; ++i) {
            for (int j = 0; j < N / 2; ++j) {
                t = matrix[i][j];
                matrix[i][j] = matrix[N - 1 - j][i];
                matrix[N - 1 - j][i] = matrix[N - 1 - i][N - 1 - j];
                matrix[N - 1 - i][N - 1 - j] = matrix[j][N - 1 - i];
                matrix[j][N - 1 - i] = t;
            }
        }
    }
};

#ifdef LOCAL

void print(const vector<vector<int>>& matrix) {
    cout << "------------------------------" << endl;
    for (auto& row: matrix) {
        for (auto elem: row) {
            cout << setw(4) << elem << " ";
        }
        cout << endl;
    }
    cout << "------------------------------" << endl;
}

int main(int argc, const char* argv[]) {
    vector<vector<int>> matrix{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    print(matrix);

    Solution sol;
    sol.rotate(matrix); print(matrix);
    sol.rotate(matrix); print(matrix);
    sol.rotate(matrix); print(matrix);
    sol.rotate(matrix); print(matrix);

    return 0;
}
#endif
