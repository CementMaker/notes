/*
Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.

*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;

        int carry = 1;
        for (auto rit = digits.rbegin(); rit != digits.rend(); ++rit) {
            result.push_back((*rit + carry) % 10);
            carry = (*rit + carry) / 10;
        }
        if (carry > 0) result.push_back(carry);
        reverse(result.begin(), result.end());
        return result;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    //vector<int> digits({5, 9, 9});
    vector<int> digits({9, 9, 9});

    for (auto d: Solution().plusOne(digits)) {
        cout << d << endl;
    }
    return 0;
}
#endif
