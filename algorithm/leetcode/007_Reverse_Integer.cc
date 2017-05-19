/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

Note:
The input is assumed to be a 32-bit signed integer.
Your function should return 0 when the reversed integer overflows.
*/
#include <iostream>
#include <string>

class Solution {
#ifdef STRING
public:
    int reverse(int x) {
        int sign = x >= 0 ? 1 : -1;
        x = abs(x);

        std::string xstr = std::to_string(x);

        int64_t res_num = 0;
        for (std::string::reverse_iterator rit = xstr.rbegin(); rit != xstr.rend(); ++rit) {
            res_num = res_num * 10 + *rit - '0';
        }
        res_num *= sign;

        if (res_num > std::numeric_limits<int>::max() || 
                            res_num < std::numeric_limits<int>::min()) {
            return 0;
        }
        return static_cast<int>(res_num);
    }
#else
public:
    int reverse(int x) {
        int64_t res_num = 0;

        while (x != 0) {
            res_num = res_num * 10 + x % 10;
            x /= 10;
        }
        if (res_num > std::numeric_limits<int>::max() || 
                            res_num < std::numeric_limits<int>::min()) {
            return 0;
        }
        return static_cast<int>(res_num);
    }

#endif
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    Solution sol;

    std::cout << sol.reverse(123) << std::endl;
    std::cout << sol.reverse(-123) << std::endl;

    return 0;
}
#endif
