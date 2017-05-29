/*
Given two non-negative integers num1 and num2 represented as strings,
return the product of num1 and num2.

Note:
    1. The length of both num1 and num2 is < 110.
    2. Both num1 and num2 contains only digits 0-9.
    3. Both num1 and num2 does not contain any leading zero.
    4. You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        vector<int> res(num1.size() + num2.size(), 0);
        for (int i = 0; i < num1.size(); ++i) {
            for (int j = 0; j < num2.size(); ++j) {
                res[i + j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        for (int i = 0; i + 1 < res.size(); ++i) {
            res[i + 1] += res[i] / 10;
            res[i] %= 10;
        }

        for (int i = res.size() - 1; i >= 0; --i) {
            if (i == 0 || res[i] != 0) {
                res.resize(i + 1);
                break;
            }
        }

        ostringstream oss;
        for (auto it = res.rbegin(); it != res.rend(); ++it) {
            oss << *it;
        }
        return oss.str();
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    Solution sol;

    cout << sol.multiply("123", "192") << endl; // 23616
    cout << sol.multiply("0", "0") << endl;
    cout << sol.multiply("3", "99") << endl;

    return 0;
}
#endif
