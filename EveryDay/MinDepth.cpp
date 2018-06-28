
/*
题目：求二叉树的最小深度
思路：注意对几种情况的分析，

*/


#include <iostream>
using namespace std;

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

class Solution 
{
public:

	int run(TreeNode *root) 
	{
		if(root == NULL)
		{
			return 0;
		}

		int leftDepth = run(root->left);
		int rightDepth = run(root->right);

		if(leftDepth == 0 || rightDepth == 0)
		{
			return leftDepth+rightDepth+1;
		}
		else
		{
			return 1+min(leftDepth,rightDepth);
		}
	}
};


void TestMinDepth()
{
	Solution s;
	TreeNode* root = new TreeNode(1);
	TreeNode* rleft = new TreeNode(2);
	TreeNode* rright = new TreeNode(3);
	TreeNode* right = new TreeNode(4);
	root->left = rleft;
	root->right = rright;
	rleft->right = right;

	cout<<s.run(root)<<endl;
}

int main()
{
	TestMinDepth();
	system("pause");
	return 0;
}