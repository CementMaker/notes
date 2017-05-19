/* Determine whether an integer is a palindrome. Do this without extra space.  */
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int64_t reverse_num = 0;

        for (int tx = x; tx != 0; tx /= 10) {
            reverse_num = reverse_num * 10 + tx % 10;
        }
        return reverse_num == x;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    Solution sol;

    cout << sol.isPalindrome(123321) << endl;
    cout << sol.isPalindrome(12321) << endl;
    cout << sol.isPalindrome(1231) << endl;

    return 0;
}
#endif
