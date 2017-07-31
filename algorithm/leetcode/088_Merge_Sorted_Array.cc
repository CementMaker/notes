/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to
hold additional elements from nums2.

The number of elements initialized in nums1 and nums2 are m and n respectively.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while (n > 0) {
            if (m > 0 && nums1[m - 1] > nums2[n - 1]) {
                nums1[m + n - 1] = nums1[m - 1];
                --m;
            } else {
                nums1[m + n - 1] = nums2[n - 1];
                --n;
            }
        }
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    vector<int> nums1{1, 3, 5, 7};
    vector<int> nums2{2, 4, 6};

    nums1.resize(nums1.size() + nums2.size());

    Solution().merge(nums1, 4, nums2, nums2.size());
    for (auto n: nums1) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
#endif
