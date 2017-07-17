/*
Implement int sqrt(int x).
Compute and return the square root of x.
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 0) return 0;
        int64_t left = 1;
        int64_t right = x;
        int64_t mid;

        int64_t ans;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (mid * mid > x) {
                right = mid - 1;
            } else {
                ans = mid;
                left = mid + 1;
            }
        }
        return ans;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    cout << Solution().mySqrt(1) << endl;
    cout << Solution().mySqrt(15) << endl;
    cout << Solution().mySqrt(16) << endl;
    cout << Solution().mySqrt(17) << endl;

    return 0;
}
#endif
