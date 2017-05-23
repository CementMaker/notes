/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/
#include <iostream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        int64_t q = dividend;
        int64_t m = divisor;
        int sign = q > 0 ? 1 : -1;
        sign = m > 0 ? sign : -sign;

        q = abs(q);
        m = abs(m);

        int64_t res = 0;
        int shift = 0;
        while (q >= m) {
            shift = 1;
            while ((m << shift) <= q) {
                ++shift;
            }
            q -= (m << (shift - 1));
            res |= (1ll << (shift - 1));
        }
        res *= sign;
        if (res > std::numeric_limits<int>::max() || res < std::numeric_limits<int>::min()) {
            return std::numeric_limits<int>::max();
        }
        return res;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    Solution sol;

    cout << sol.divide(10, 3) << endl;
    cout << sol.divide(100000, 33) << endl;
    cout << sol.divide(-100000, 33) << endl;
    cout << sol.divide(-1, 1) << endl;
    cout << sol.divide(-1000, 1) << endl;
    cout << sol.divide(-2147483648, -1) << endl;

    return 0;
}
#endif
