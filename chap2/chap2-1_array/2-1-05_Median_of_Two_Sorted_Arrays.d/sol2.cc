#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	template <typename It>
	double nth_elem(It ib1, It ie1, It ib2, It ie2, decltype(ie1-ib1) n) {
		
		if (ie1 - ib1 > ie2 - ib2) {std::swap(ie2,ie1); std::swap(ib1,ib2);}
		if (ie1 == ib1) return *(ib2 + n);
		if (n == 0) return std::min(*ib1,*ib2);
		
		auto half = std::min((n + 1) >> 1,ie1-ib1) - 1;
		auto half2 = n - half - 1;
		if (*(ib1 + half) == *(ib2 + half2)) return *(ib1 + half);
		else if (*(ib1 + half) < *(ib2 + half2)) return nth_elem(ib1+half+1,ie1,ib2,ie2,half2);
		else return nth_elem(ib1,ie1,ib2 + half2 + 1,ie2,half);
	
	}
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		auto len1 = nums1.size(), len2 = nums2.size();
		auto len = len1 + len2;
		if (len % 2 == 1) return nth_elem(begin(nums1),end(nums1),begin(nums2),end(nums2),len>>1);
		else return (nth_elem(begin(nums1),end(nums1),begin(nums2),end(nums2),len>>1) + 
								nth_elem(begin(nums1),end(nums1),begin(nums2),end(nums2),(len>>1)-1))/2;
	}
};

int main() {
	std::vector<int> v1 = {1,2,3,4,5,6,7,8};
	std::vector<int> v2 = {4,5,6,7,8,9,10,11,12};
	Solution sol;
	std::cout << sol.findMedianSortedArrays(v1,v2) << std::endl;
	return 0;
}
