/*
Implement next permutation, which rearranges numbers into the lexicographically next greater
permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order
(ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples.

Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if (num.size() <= 1) return;

        int reverse_beg = num.size() - 1;
        while (reverse_beg > 0 && num[reverse_beg] <= num[reverse_beg - 1]) {
            --reverse_beg;
        }
        for (int left = reverse_beg, right = num.size() - 1; left < right; ++left, --right) {
            swap(num[left], num[right]);
        }
        if (reverse_beg == 0) return;

        auto it = upper_bound(num.begin() + reverse_beg, num.end(), num[reverse_beg - 1]);
        swap(*it, num[reverse_beg - 1]);
    }

};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    Solution sol;

    vector<int> num = {1, 2, 3};
    sol.nextPermutation(num); for (auto n: num) { cout << n << " "; } cout << endl;
    cout << "---------------------------------------" << endl;

    num = {3, 2, 1};
    sol.nextPermutation(num); for (auto n: num) { cout << n << " "; } cout << endl;
    cout << "---------------------------------------" << endl;

    num = {1, 1, 5, 1};
    sol.nextPermutation(num); for (auto n: num) { cout << n << " "; } cout << endl;
    cout << "---------------------------------------" << endl;

    num = {0, 1, 1, 0, 4, 4};
    sol.nextPermutation(num); for (auto n: num) { cout << n << " "; } cout << endl;
    cout << "---------------------------------------" << endl;

    return 0;
}
#endif
