#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	string tree2str(TreeNode* t) {
		if (t == NULL) {
			return "";
		}

		string ret = str2int(t->val);
		if (t->left == NULL && t->right == NULL) {
			return ret;
		}

		ret += "(" + tree2str(t->left) + ")";

		if (t->right != NULL) {
			ret += "(" + tree2str(t->right) + ")";
		}

		return ret;
	}
private:
	string str2int(int num) {
		stringstream ss;
		ss << num;
		string s;
		ss >> s;

		return s;
	}
};

int main()
{
	//eg1
	TreeNode *eg1Node1 = new TreeNode(1);
	TreeNode *eg1Node2 = new TreeNode(2);
	TreeNode *eg1Node3 = new TreeNode(3);
	TreeNode *eg1Node4 = new TreeNode(4);

	eg1Node2->left = eg1Node4;
	eg1Node1->left = eg1Node2;
	eg1Node1->right = eg1Node3;

	//eg2
	TreeNode *eg2Node1 = new TreeNode(1);
	TreeNode *eg2Node2 = new TreeNode(2);
	TreeNode *eg2Node3 = new TreeNode(3);
	TreeNode *eg2Node4 = new TreeNode(4);

	eg2Node2->right = eg2Node4;
	eg2Node1->left = eg2Node2;
	eg2Node1->right = eg2Node3;

	Solution solution;
	cout << solution.tree2str(eg1Node1) << endl;
	cout << solution.tree2str(eg2Node1) << endl;

	return 0;
}