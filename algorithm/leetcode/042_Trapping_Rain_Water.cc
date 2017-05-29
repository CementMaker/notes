/*
Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
#ifdef SIMPLE
public:
    int trap(vector<int>& height) {
        vector<int> left(height.size(), 0);
        for (int i = 1; i < height.size(); ++i) {
            left[i] = max(left[i - 1], height[i - 1]);
        }

        vector<int> right(height.size(), 0);
        for (int i = height.size() - 2; i >= 0; --i) {
            right[i] = max(right[i + 1], height[i + 1]);
        }

        int res = 0;
        for (int i = 0; i < height.size(); ++i) {
            res += max(0, min(left[i], right[i]) - height[i]);
        }
        return res;
    }

#else

public:
    int trap(vector<int>& height) {
        stack<int> s;

        int res = 0;
        int pre_height = 0;
        for (int i = 0; i < height.size(); ++i) {
            pre_height = 0;
            while (!s.empty() && height[s.top()] <= height[i]) {
                res += (height[s.top()] - pre_height) * (i - s.top() - 1);
                pre_height = height[s.top()];
                s.pop();
            }
            if (!s.empty()) {
                res += (i - s.top() - 1) * (height[i] - pre_height);
            }
            s.push(i);
        }
        return res;
    }
#endif
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    Solution sol;
    vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << sol.trap(height) << endl;
    cout << "---------------------------" << endl;

    height = {4, 2, 3};
    cout << sol.trap(height) << endl;

    return 0;
}
#endif
