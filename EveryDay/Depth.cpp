#include <iostream>
using namespace std;

/*
	二叉树的深度
	描述：输入一棵二叉树，求该树的深度。
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
	int TreeDepth(TreeNode* pRoot)
	{
		if(pRoot == NULL)
		{
			return 0;
		}

		int leftDepth = TreeDepth(pRoot->left);
		int rightDepth = TreeDepth(pRoot->right);

		return leftDepth>rightDepth ? leftDepth+1 :rightDepth+1;
	}
};

void TestDepth()
{
	Solution s;
	TreeNode* root = new TreeNode(1);
	TreeNode* rleft = new TreeNode(2);
	TreeNode* rright = new TreeNode(3);
	TreeNode* right = new TreeNode(4);
	root->left = rleft;
	root->right = rright;
	rleft->right = right;

	cout<<s.TreeDepth(root)<<endl;
}

int main()
{
	TestDepth();

	system("pause");
	return 0;
}