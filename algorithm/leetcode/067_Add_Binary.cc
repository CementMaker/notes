/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        if (a.size() >= b.size()) {
            res = a;
            //swap(a, b);
            a = b;
        } else {
            res = b;
        }
        reverse(a.begin(), a.end());
        reverse(res.begin(), res.end());

        int carry = 0;
        for (int i = 0; i < a.size(); ++i) {
            carry = res[i] - '0' + a[i] - '0' + carry;
            res[i] = (carry & 1) + '0';
            carry >>= 1;
        }
        for (int i = a.size(); i < res.size(); ++i) {
            carry = res[i] - '0' + carry;
            res[i] = (carry & 1) + '0';
            carry >>= 1;
        }
        if (carry > 0) res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {

    cout << Solution().addBinary("11", "1") << endl;

    return 0;
}
#endif
