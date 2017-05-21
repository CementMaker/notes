/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate(i, ai).
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).

Find two lines, which together with x-axis forms a container, such that the container contains
the most water.

Note: You may not slant the container and n is at least 2.
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() <= 1) {
            return 0;
        }

        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;
        while (left < right) {
            max_area = max(max_area, (right - left) * min(height[left], height[right]));
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return max_area;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    Solution sol;
    vector<int> height = {3, 2, 1, 5, 7, 4, 3, 9};

    cout << sol.maxArea(height) << endl;
    return 0;
}
#endif
