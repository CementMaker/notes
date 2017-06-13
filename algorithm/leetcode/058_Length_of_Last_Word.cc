/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.size() == 0) return 0;

        int res = 0;
        int pos = s.size() - 1;
        while (pos >= 0 && isspace(s[pos])) --pos;
        while (pos >= 0 && !isspace(s[pos])) --pos, ++res;

        return res;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    cout << Solution().lengthOfLastWord("Hello World") << endl;
    return 0;
}
#endif
