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

	for (int *i = start, *imx = done - 1; i < imx - 1; ++i) {
		if (*i + *(i + 1) + *(i + 2) > target) break;
		while ((i > start && *i == *(i - 1)) || *i + *(imx - 1) + *imx < target) ++i;
		int iv = *i;
		while (iv + *(i + 1) + *imx > target) --imx;

		for (int *j = i + 1, *k = imx; j < k;) {
			if (iv + *j + *k < target) while(++j < k && *j == *(j - 1));
			else if (iv + *j + *k > target) while(j < --k && *k == *(k + 1));
			else {
				int arrSize = sizeof(int*) * (++retSize);
				int **arr = (int**)malloc(arrSize), **tmp = ret;
				int *triplet = (int*)malloc(sizeof(int) * 3); triplet[0] = iv; triplet[1] = *j; triplet[2] = *k;
				memcpy(arr, ret, arrSize - sizeof(int*)); arr[retSize - 1] = triplet;
				ret = arr;
				free(tmp);
				while(++j < k && *j == *(j - 1));
				while(j < --k && *k == *(k + 1));
			}
		}
	}

	*returnSize = retSize;
	return ret;
}
