/*
Given n non-negative integers representing the histogram's bar height where
the width of each bar is 1, find the area of largest rectangle in the histogram.

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given heights = [2,1,5,6,2,3],
return 10.
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:

#ifdef NAIVE

    int largestRectangleArea(vector<int>& heights) {
        vector<int> width(heights.size(), 0);

        stack<int> s;
        for (int i = 0; i < heights.size(); ++i) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            if (s.empty()) width[i] = i + 1;
            else width[i] = i - s.top();
            s.push(i);
        }
        while (!s.empty()) s.pop();

        for (int i = int(heights.size()) - 1; i >= 0; --i) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            if (s.empty()) width[i] += int(heights.size()) - i - 1;
            else width[i] += s.top() - i - 1;
            s.push(i);
        }

        int res = 0;
        for (int i = 0; i < heights.size(); ++i) {
            res = max(res, heights[i] * width[i]);
        }
        return res;
    }

#else

    int largestRectangleArea(vector<int>& heights) {
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        
        int res = 0;
        int calc_idx = 0;

        stack<int> s;
        for (int i = 0; i < heights.size(); ++i) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
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

#endif
};


#ifdef LOCAL
int main(int argc, const char* argv[]) {
    vector<int> heights({2, 1, 5, 6, 2, 3});

    cout << Solution().largestRectangleArea(heights) << endl;

    return 0;
}
#endif
