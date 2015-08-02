#include <string>
#include <numeric>
#include <cstdio>
using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		string s(n, '0');
		iota(begin(s), end(s), '1');
		for(; k > 0; --k) {
			next_permutation(begin(s), end(s));
		}
		return s;
	}
};
