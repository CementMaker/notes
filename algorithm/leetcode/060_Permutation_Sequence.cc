/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string res("123456789", n);

        int mod = 1;
        for (int i = 2; i <= n; ++i) mod *= i;
        k = (k - 1) % mod + 1;

        while (--k) {
            next_permutation(res.begin(), res.end());
        }
        return res;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    cout << Solution().getPermutation(3, 4) << endl;
    cout << Solution().getPermutation(1, 1) << endl;

    return 0;
}
#endif
