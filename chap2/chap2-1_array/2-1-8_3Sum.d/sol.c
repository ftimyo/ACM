/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <string.h>
static int compare (const void * a, const void * b) {
  return ( *(int*)a - *(int*)b );
}

int** threeSum(int* nums, int numsSize, int* returnSize) {
        int **ret = NULL, retSize = 0;
        if (numsSize < 3) {*returnSize = retSize; return ret;}
        int target = 0;
        int *start = nums, *done = nums + numsSize;
        qsort(start, numsSize, sizeof(int), compare);

        for (int *i = start; i < done - 2; ++i) {
            if (i > start && *i == *(i-1)) continue; /*remove duplicate numbers*/
            for (int *j = i + 1, *k = done - 1; j != k;) {
                if (j > i + 1 && *j == *(j-1)) {++j; continue;}
                if (k < done - 1 && *k == *(k+1)) {--k; continue;}
                int sum = *i + *j + *k;
                if (sum < target) ++j;
                else if (sum > target) --k;
                else {
                    int arrSize = sizeof(int*) * (++retSize);
                    int **arr = (int**)malloc(arrSize), **tmp = ret;
                    int *tuple = (int*)malloc(sizeof(int) * 3); tuple[0] = *i; tuple[1] = *j; tuple[2] = *k;
                    memcpy(arr, ret, arrSize - sizeof(int*)); arr[retSize - 1] = tuple;
                    ret = arr; free(tmp);
                    ++j;
                }
            }
        }
        *returnSize = retSize;
        return ret;
}
