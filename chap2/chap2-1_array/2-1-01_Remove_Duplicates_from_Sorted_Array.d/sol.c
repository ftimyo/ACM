int removeDuplicates(int* nums, int numsSize) {
    if (numsSize < 2) return numsSize;
    int *e = nums + numsSize;
    int *i1 = nums + 1, *i2 = i1;
    for (;i2 < e; ++i2) {
        if (*(i1-1) != *i2) {*i1 = *i2; ++i1;}
    }
    return i1 - nums;
}
