#include <stack>
#include <vector>
/**
 * Definition for a binary tree node.
*/
struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
 */
class Solution {
public:
	std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
		std::vector<std::vector<int> > ret;
		if (!root) return ret;
		std::stack<TreeNode*> s1, s2;
		s1.push(root);
		while (!s1.empty() || !s2.empty()) {
			std::vector<int> level;
			while (!s1.empty()) {
				auto p = s1.top(); s1.pop();
				level.push_back(p->val);
				if (p->left) s2.push(p->left);
				if (p->right) s2.push(p->right);
			}
			if (!level.empty()) ret.emplace_back(std::move(level));
			level.clear();
			while (!s2.empty()) {
				auto p = s2.top(); s2.pop();
				level.push_back(p->val);
				if (p->right) s1.push(p->right);
				if (p->left) s1.push(p->left);
			}
			if (!level.empty()) ret.emplace_back(std::move(level));
		}
		return ret;
	}
};
