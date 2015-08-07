#include <stdlib.h>
int compare (const void * a, const void * b) {
  return ( *(int*)a - *(int*)b );
}

int threeSumClosest(int* nums, int numsSize, int target) {
	int d = ~(1<<31);
	qsort(nums, numsSize, sizeof(int), compare);
	int *b = nums, *e = nums + numsSize;
	for (int *i = b; i < e - 2; ++i) {
		for (int *j = i + 1, *k = e - 1; j < k;) {
			int delta = target - (*i + *j + *k);
			d = abs(delta) < abs(d) ? delta : d;
			if (delta > 0) ++j;
			else if (delta < 0) --k;
			else return target;
		}
	}
	return target - d;
}
