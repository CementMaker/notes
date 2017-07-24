/*
Given a 2D binary matrix filled with 0's and 1's,
find the largest rectangle containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Return 6.
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;

        int res = 0;
        vector<int> heights(matrix[0].size(), 0);
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == '1') ++heights[j];
                else heights[j] = 0;
            }
            res = max(res, largestRectangleArea(heights));
        }
        return res;
    }

private:
    int largestRectangleArea(vector<int>& heights) {
        heights.insert(heights.begin(), 0);
        heights.push_back(0);

        int res = 0;
        int calc_idx = 0;
        stack<int> s;
        for (int i = 0; i < heights.size(); ++i) {
            while (!s.empty() && heights[i] < heights[s.top()]) {
                calc_idx = s.top();
                s.pop();
                res = max(res, heights[calc_idx] * (i - s.top() - 1));
            }
            s.push(i);
        }

        heights.erase(heights.begin());
        heights.pop_back();
        return res;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    vector<vector<char>> matrix{
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    cout << Solution().maximalRectangle(matrix) << endl;
    return 0;
}
#endif
