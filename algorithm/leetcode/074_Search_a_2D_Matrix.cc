/*
Write an efficient algorithm that searches for a value in an m x n matrix.
This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
    [1,   3,  5,  7],
    [10, 11, 16, 20],
    [23, 30, 34, 50]
]

Given target = 3, return true.

*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;

        int row = matrix.size();
        int col = matrix[0].size();

        int left = 0;
        int right = row * col - 1;
        int mid = 0;
        while (left <= right) {
            mid = left + ((right - left) >> 1);

            if (matrix[mid / col][mid % col] == target) return true;
            else if (matrix[mid / col][mid % col] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    vector<vector<int>> matrix({{1,   3,  5,  7},
                                {10, 11, 16, 20},
                                {23, 30, 34, 50}});
    for (int i = 0; i <= 55; ++i) {
        cout << i << " => " << Solution().searchMatrix(matrix, i) << endl;
    }

    return 0;
}
#endif
