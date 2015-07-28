#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int is_even = (nums1.size() + nums2.size()) % 2 == 0;
        int midx = (nums1.size() + nums2.size()) / 2;
        int current = 0, median = 0, idx = 0;
        auto i = begin(nums1), j = begin(nums2), e1 = end(nums1), e2 = end(nums2);

        for (; i != e1 && j != e2; ++idx) {
            if (*i < *j) current = *(i++);
            else current = *(j++);
            if (is_even) {
                if (idx == midx - 1) median = current;
                if (idx == midx) return (median + current) / 2.0;
            } else {
                if (idx == midx) return current;
            }
        }

        for (; i != e1; ++i, ++idx) {
            if (is_even) {
                if (idx == midx - 1) median = *i;
                if (idx == midx) return (median + *i) / 2.0;
            } else {
                if (idx == midx) return *i;
            }
        }

        for (; j != e2; ++j, ++idx) {
            if (is_even) {
                if (idx == midx - 1) median = *j;
                if (idx == midx) return (median + *j) / 2.0;
            } else {
                if (idx == midx) return *j;
            }
        }
    }
};
