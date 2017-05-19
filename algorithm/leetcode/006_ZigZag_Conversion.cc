/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)
        P   A   H   N
        A P L S I I G
        Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

    string convert(string text, int nRows);

convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        string result;
        for (int row = 1; row <= numRows; ++row) {
            for (int i = row - 1; i < s.size(); i += 2 * numRows - 2) {
                result.push_back(s[i]);
                if (row != 1 && row != numRows && i + 2 * numRows - 2 * row < s.size()) {
                    result.push_back(s[i + 2 * numRows - 2 * row]);
                }
            }
        }
        return result;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    Solution sol;

    cout << sol.convert("PAYPALISHIRING", 3) << endl;
    cout << sol.convert("A", 1) << endl;
    cout << sol.convert("AB", 3) << endl;

    return 0;
}
#endif
