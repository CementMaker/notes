/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
*/

#include <iostream>
#include <sstream>
#include <string>
#include <deque>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        deque<string> stk;

        istringstream ss(path);
        string part;
        while (getline(ss, part, '/')) {
            if (part.size() == 0 || part == ".") continue;

            if (part == ".." && !stk.empty()) stk.pop_back();
            else if (part != "..") stk.push_back(part);
        }
        string res;
        while (!stk.empty()) {
            res += "/" + stk.front();
            stk.pop_front();
        }
        return res.empty() ? "/" : res;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    cout << Solution().simplifyPath("/home/") << endl;
    cout << Solution().simplifyPath("/a/./b/../../c/") << endl;
    cout << Solution().simplifyPath("/../") << endl;
    cout << Solution().simplifyPath("/home//foo/") << endl;

    return 0;
}
#endif
