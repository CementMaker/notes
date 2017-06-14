/*
Validate if a given string is numeric.

Some examples:
"0"   => true
"0.1" => true
"abc" => false
"1 a" => false
"2e10" => true

Note: It is intended for the problem statement to be ambiguous.
You should gather all requirements up front before implementing one.
*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int i = 0;

        while (isspace(s[i])) ++i;

        if (s[i] == '+' || s[i] == '-') ++i;

        int n_nm, n_pt;
        for (n_nm = 0, n_pt = 0; isdigit(s[i]) || s[i] == '.'; ++i) {
            s[i] == '.' ? ++n_pt : ++n_nm;
        }
        if (n_pt > 1 || n_nm < 1) {// no more than one point, at least one digit
            return false;
        }

        // check the exponent if exist
        if (s[i] == 'e') {
            ++i;
            if (s[i] == '+' || s[i] == '-') ++i;
            
            int n_nm = 0;
            while (isdigit(s[i])) ++i, ++n_nm;

            if (n_nm < 1) return false;
        }

        // skip the trailing whitespaces
        while (isspace(s[i])) ++i;
        
        return s[i] == '\0';
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {

    cout << Solution().isNumber("0") << endl;
    cout << Solution().isNumber("0.1") << endl;
    cout << Solution().isNumber("abc") << endl;
    cout << Solution().isNumber("1 a") << endl;
    cout << Solution().isNumber("2e10") << endl;
    cout << Solution().isNumber("1 ") << endl;
    cout << Solution().isNumber("3. ") << endl;

    return 0;
}
#endif
