#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}	
};

/******************************* 迭代版本 ***************************/
//int getSum(vector<int> v)
//{
//	int sum = 0;
//	int vSize = v.size()-1;
//
//	for (int i = 0; i < v.size(); i++)
//	{
//		int j = i;
//		int tmp = v[i];
//		while (j < vSize)
//		{
//			tmp *= 10;
//			j++;
//		}
//
//		sum += tmp;
//	}
//
//	return sum;
//}
//
//int sumNumbers(TreeNode* root) {
//	int sum = 0;
//	if (root != NULL)
//	{
//		stack<TreeNode*> s;
//		s.push(root);
//
//		vector<int> rootv;
//		rootv.push_back(root->val);
//
//		stack<vector<int>> sumS;
//		sumS.push(rootv);
//
//		while (!s.empty())
//		{
//			TreeNode *node = s.top();
//			s.pop();
//
//			vector<int> v = sumS.top();
//			sumS.pop();
//			
//			if (node->right != NULL)
//			{
//				s.push(node->right);
//
//				vector<int> leftV = v;
//				leftV.push_back(node->right->val);
//				sumS.push(leftV);
//			}
//			
//			if (node->left != NULL)
//			{
//				s.push(node->left);
//				vector<int> rightV = v;
//				rightV.push_back(node->left->val);
//				sumS.push(rightV);
//			}
//
//			if (node->right == NULL && node->left == NULL)//树的叶子节点
//			{
//				int leafSum = getSum(v);
//				sum += leafSum;
//			}
//		}
//	}
//
//	return sum;
//}


/******************************* 递归版本 ***************************/
void sumNumbersHelper(TreeNode *root,string s,int& sum)
{
	if (root != NULL)
	{
		string tmpS = s;
		if (root->left == NULL && root->right == NULL) //叶子节点
		{
			s = s + char(root->val + '0');

			stringstream ss;
			ss << s;
			int numS;
			ss >> numS;

			sum += numS;
		}
		
		if (root->left != NULL)
		{
			s = tmpS + char(root->val+'0');
			sumNumbersHelper(root->left, s, sum);
		}

		if (root->right != NULL)
		{
			s = tmpS + char(root->val+'0');
			sumNumbersHelper(root->right,s,sum);
		}
	}
}

int sumNumbers(TreeNode *root)
{
	int sum = 0;

	sumNumbersHelper(root,"",sum);

	return sum;
}

int main()
{
	TreeNode *root = new TreeNode(1);
	TreeNode *node1 = new TreeNode(2);
	TreeNode *node2 = new TreeNode(3);

	TreeNode *node3 = new TreeNode(4);
	TreeNode *node4 = new TreeNode(5);
	TreeNode *node6 = new TreeNode(6);

	root->left = node1;
	root->right = node2;

	node1->left = node3;
	node1->right = node4;

	node2->right = node6;


	cout << sumNumbers(root);

	return 0;
}
