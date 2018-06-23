
/*
	�ԳƵĶ�����
	��Ŀ��������ʵ��һ�������������ж�һ�Ŷ������ǲ��ǶԳƵġ�
	ע�⣬���һ��������ͬ�˶������ľ�������ͬ�ģ�������Ϊ�ԳƵġ�
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

bool isSymmetricalCore(TreeNode* left, TreeNode* right)
{
	if(left == NULL && right == NULL)
	{
		return true;
	}

	if(left == NULL || right == NULL)
	{
		return false;
	}

	if(left->val == right->val)
	{
		return isSymmetricalCore(left->left,right->right) && isSymmetricalCore(left->right,right->left);
	}

	return false;
}

bool isSymmetrical(TreeNode* pRoot)
{
	if(pRoot == NULL)
		return true;

	return isSymmetricalCore(pRoot->left,pRoot->right);
}

void TestSym()
{

	TreeNode* root = new TreeNode(1);
	TreeNode* rleft = new TreeNode(2);
	TreeNode* rright = new TreeNode(2);
	//TreeNode* right = new TreeNode(4);
	root->left = rleft;
	root->right = rright;
	//rleft->right = right;

	cout<<isSymmetrical(root)<<endl;
}

int main()
{
	TestSym();

	system("pause");
	return 0;
}