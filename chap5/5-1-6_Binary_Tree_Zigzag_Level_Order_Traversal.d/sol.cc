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
		std::stack<TreeNode*> k[2];
		std::vector<std::vector<int>> res;
		int i = 0;
		if (root != nullptr) k[i].push(root);
		while (!k[i].empty()) {
			auto j = 1^i;
			std::vector<int> level;
			while (!k[i].empty()) {
				auto p = k[i].top();
				k[i].pop();
				if (i == 0) {
					if (p->left != nullptr) k[j].push(p->left);
					if (p->right != nullptr) k[j].push(p->right);
				} else {
					if (p->right != nullptr) k[j].push(p->right);
					if (p->left != nullptr) k[j].push(p->left);
				}
				level.push_back(p->val);
			}
			i = j;
			if (!level.empty()) res.emplace_back(std::move(level));
		}
		return res;
	}
};
