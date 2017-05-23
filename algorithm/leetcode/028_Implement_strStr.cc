/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack,
or -1 if needle is not part of haystack.
*/
#include <iostream>
#include <string>

using namespace std;

//TODO KMP algorithm
class Solution {
public:
    int strStr(const string& haystack, const string& needle) {
        for (int i = 0; i + needle.size() <= haystack.size(); ++i) {
            if (strncmp(haystack.c_str() + i, needle.c_str(), needle.size()) == 0) {
                return i;
            }
        }
        return -1;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    Solution sol;
    cout << sol.strStr("hello world", "hello") << endl;
    cout << sol.strStr("hello world", "word") << endl;
    cout << sol.strStr("hello world", "world") << endl;

    return 0;
}
#endif
