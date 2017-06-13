/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
    [ 1, 2, 3 ],
    [ 8, 9, 4 ],
    [ 7, 6, 5 ]
]
*/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));

        int val = 1;
        for (int i = 0; i < n / 2; ++i) {
            for (int j = i; j <= n - 1 - i; ++j) {
                res[i][j] = val++;
            }

            for (int j = i + 1; j < n - 1 - i; ++j) {
                res[j][n - 1 - i] = val++;
            }

            for (int j = n - 1 - i; j >= i; --j) {
                res[n - 1 - i][j] = val++;
            }

            for (int j = n - 2 - i; j > i; --j) {
                res[j][i] = val++;
            }
        }

        if (n & 1) res[n / 2][n / 2] = n * n;
        return res;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {

    for (int k = 2; k <= 8; ++k) {
        for (auto& row: Solution().generateMatrix(k)) {
            for (auto& col: row) {
                cout << setw(2) << col << " ";
            }
            cout << endl;
        }
        cout << "-------------------------------------------" << endl;
    }
    return 0;
}
#endif
