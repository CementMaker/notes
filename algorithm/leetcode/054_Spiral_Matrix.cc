/*
Given a matrix of m x n elements (m rows, n columns),
return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
    [ 1, 2, 3 ],
    [ 4, 5, 6 ],
    [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        if (matrix.size() == 0) return {};
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> res;
        int lim = min(m / 2, n / 2);
        
        for (int i = 0; i < lim; ++i) {
            for (int j = i; j < n - i; ++j) res.push_back(matrix[i][j]);
            
            for (int j = i + 1; j < m - i - 1; ++j) res.push_back(matrix[j][n - i - 1]);
            
            for (int j = n - i - 1; j >= i; --j) res.push_back(matrix[m - i - 1][j]);
        
            for (int j = m - i - 2; j >= i + 1; --j) res.push_back(matrix[j][i]);
        }
        if (m >= n && (n & 1)) {
            for (int i = lim; i < m - lim; ++i) {
                res.push_back(matrix[i][lim]);
            }
        } else if (n > m && (m & 1)) {
            for (int i = lim; i < n - lim; ++i) {
                res.push_back(matrix[lim][i]);
            }
        }
        return res;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    for (auto n: Solution().spiralOrder(matrix)) {
        cout << n << endl;
    }
    return 0;
}
#endif
