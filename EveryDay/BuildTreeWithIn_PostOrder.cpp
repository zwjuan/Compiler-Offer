
/*
	题目：知道中序遍历和后序遍历构造二叉树
	思路：类比前序遍历、中序遍历构造二叉树，前序遍历前面的结点为根结点，后序遍历最后的结点为根节点。
*/

#include <iostream>
#include <vector>

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

class Solution {
public:
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) 
	{
		return buildTree(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);

	}

	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder, int instart, int inend, int poststart, int postend)
	{
		if(instart > inend || poststart>postend)
		{
			return NULL;
		}

		TreeNode* root = new TreeNode(postorder[postend]);
		int flag = -1; //记录下标的位置
		for(int i=instart; i<=inend; ++i)
		{
			if(postorder[postend] == inorder[i])
			{
				flag = i;
				break;
			}
		}

		root->left = buildTree(inorder,postorder,instart,flag-1,poststart,poststart+flag-instart-1);
		root->right = buildTree(inorder,postorder,flag+1,inend,postend-inend+flag,postend-1);

		return root;
	}
};

void TestConstructTree()
{
	Solution s;
	TreeNode* root = new TreeNode(1);
	TreeNode* rleft = new TreeNode(2);
	TreeNode* rright = new TreeNode(3);
	TreeNode* right = new TreeNode(4);
	root->left = rleft;
	root->right = rright;
	rleft->right = right;

	int a[] = {2,4,1,3}; //中序遍历
	int b[] = {4,2,3,1}; //后序遍历
	vector<int> inorder(a,a+sizeof(a)/sizeof(a[0]));
	vector<int> postorder(b,b+sizeof(b)/sizeof(b[0]));

	TreeNode* ret = s.buildTree(inorder,postorder);
}

int main()
{
	TestConstructTree();

	system("pause");
	return 0;
}