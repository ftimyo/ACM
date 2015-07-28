double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int is_even = (nums1Size + nums2Size) % 2 == 0;
    int midx = (nums1Size + nums2Size) / 2;
    int current = 0, median = 0, idx = 0;
    int *i = nums1, *j = nums2, *e1 = nums1 + nums1Size, *e2 = nums2 + nums2Size;

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
