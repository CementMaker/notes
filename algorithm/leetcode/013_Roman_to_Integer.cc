/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

#include <iostream>

using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        if (s.find("IV") != -1 || s.find("IX") != -1) { sum -= 2; }
        if (s.find("XL") != -1 || s.find("XC") != -1) { sum -= 20; }
        if (s.find("CD") != -1 || s.find("CM") != -1) { sum -= 200; }
        int len = s.length();
        for (int i = 0; i != len; ++i) {
            switch(s[i]) {
                case 'M': sum += 1000; break;
                case 'D': sum += 500; break;
                case 'C': sum += 100; break;
                case 'L': sum += 50; break;
                case 'X': sum += 10; break;
                case 'V': sum += 5; break;
                case 'I': sum += 1; break;
                default: break;
            }
        }
        return sum;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    Solution sol;

    cout << sol.romanToInt("XI") << endl;
    cout << sol.romanToInt("IX") << endl;

    return 0;
}
#endif
