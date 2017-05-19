/*
String to Integer (atoi)

Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases.
If you want a challenge, please do not see below and ask yourself what
are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs).
You are responsible to gather all the input requirements up front.
*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int idx = 0;
        while (idx < str.size() && isspace(str[idx])) {
            ++idx;
        }

        int sign = 1;
        if (idx < str.size() && (str[idx] == '-' || str[idx] == '+')) {
            if (str[idx] == '-') {
                sign = -1;
            }
            ++idx;
        }

        int64_t result = 0;
        while (idx < str.size() && isdigit(str[idx])) {
            result = result * 10 + str[idx] - '0';
            if (sign * result > std::numeric_limits<int>::max()) {
                return std::numeric_limits<int>::max();
            } else if (sign * result < std::numeric_limits<int>::min()) {
                return std::numeric_limits<int>::min();
            }
            ++idx;
        }
        return static_cast<int>(result * sign);
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    Solution sol;

    cout << sol.myAtoi("123") << endl;
    cout << sol.myAtoi("4294967296") << endl;
    cout << sol.myAtoi("-4294967296") << endl;
    cout << sol.myAtoi("2147483648") << endl;

    return 0;
}
#endif
