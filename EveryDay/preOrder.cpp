
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
	前序非递归遍历
*/

struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;

	TreeNode(int x) 
		:val(x)
		,left(NULL)
		,right(NULL) 
	{}

};

class Solution {
public:
	vector<int> preorderTraversal(TreeNode *root)
	{
		vector<int> v;

		TreeNode* cur = root;
		stack<TreeNode*> s; 
		while( cur || !s.empty())
		{
			while(cur)
			{
				v.push_back(cur->val);
				s.push(cur);
				cur = cur->left;
			}

			//cur为NULL，说明左边遍历完成
			cur = s.top();
			s.pop();
			cur = cur->right;
		}

		return v;
	}

};

void TestTraversal()
{
	Solution s;
	TreeNode* root = new TreeNode(1);
	TreeNode* rleft = new TreeNode(2);
	TreeNode* rright = new TreeNode(3);
	TreeNode* right = new TreeNode(4);
	root->left = rleft;
	root->right = rright;
	rleft->right = right;

	vector<int>  v = s.preorderTraversal(root);
}

int main()
{

	TestTraversal();

	system("pause");
	return 0;
}