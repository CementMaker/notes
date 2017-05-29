/* Implement pow(x, n).  */

#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;

        uint64_t N = n;
        if (n < 0) {
            N = -n;
        }

        double t = x;
        while (N > 0) {
            if (N & 1) res *= t;
            t *= t;
            N >>= 1;
        }
        return n > 0 ? res : 1 / res;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    cout << Solution().myPow(2, 3) << endl;
    cout << Solution().myPow(4.2, 3) << endl;
    cout << Solution().myPow(34.00515, -3) << endl;
    return 0;
}
#endif
