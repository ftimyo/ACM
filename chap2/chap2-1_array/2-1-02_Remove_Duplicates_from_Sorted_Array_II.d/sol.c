int removeDuplicates(int* nums, int numsSize) {
    if (numsSize < 3) return numsSize;
    int *e = nums+numsSize,*i1 = nums + 2,*i2 = i1;
    for (;i2 < e; ++i2){
        if (*(i1-2)!=*i2) {
            *i1 = *i2; ++i1;
        }
    }
    return i1 - nums;
}
