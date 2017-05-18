/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log(m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
#ifdef TOPK
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        int left = findPosValue(nums1.begin(), nums1.size(),
                                nums2.begin(), nums2.size(), (len + 1) >> 1);
        int right = findPosValue(nums1.begin(), nums1.size(),
                                 nums2.begin(), nums2.size(), (len + 2) >> 1);
        return (left + right) / 2.0;
    }

private:
    int findPosValue(vector<int>::const_iterator iter1, int len1, 
                     vector<int>::const_iterator iter2, int len2,
                     int pos) {
        if (len1 == 0) return *(iter2 + pos - 1);
        if (len2 == 0) return *(iter1 + pos - 1);
        if (pos == 1) return min(*iter1, *iter2);

        int n1 = min(pos / 2, len1);
        int n2 = min(pos / 2, len2);

        if (*(iter1 + n1 - 1) > *(iter2 + n2 - 1)) {
            return findPosValue(iter1, len1, iter2 + n2, len2 - n2, pos - n2);
        } else {
            return findPosValue(iter1 + n1, len1 - n1, iter2, len2, pos - n1);
        }
    }

#else

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int N1 = nums1.size();
        int N2 = nums2.size();
        if (N1 < N2) return findMedianSortedArrays(nums2, nums1);
        if (N2 == 0) return (nums1[(N1 - 1) / 2] + nums1[N1 / 2]) / 2.0;

        int lo = 0, hi = N2 * 2;
        // Represent [1, 2, 3] as [#, 1, #, 2, #, 3, #] for easy indexing.
        while (lo <= hi) {
            int mid2 = (lo + hi) / 2;
            int mid1 = N1 + N2 - mid2;

            int L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1 - 1) / 2];
            int L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2 - 1) / 2];
            int R1 = (mid1 == N1 * 2) ? INT_MAX : nums1[mid1 / 2];
            int R2 = (mid2 == N2 * 2) ? INT_MAX : nums2[mid2 / 2];
            
            if (L1 > R2) lo = mid2 + 1;
            else if (L2 > R1) hi = mid2 - 1;
            else return (max(L1, L2) + min(R1, R2)) / 2.0;
        }
        return -1;
    }

#endif
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    Solution sol;
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};

    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
#endif
