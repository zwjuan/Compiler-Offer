/*
	��Ŀ���ж�һ�����ǲ���ƽ�������
	�������ݹ��ж�ÿ�������Ƿ���ƽ��������߶ȵ�ʱ�����ÿ�������ĸ߶ȣ����Ч��
*/

#include<iostream>
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
	bool IsBalanceCore(TreeNode* Root,int& Height)
	{
		if(Root == NULL)
		{
			Height = 0;
			return true;
		}

		int leftHeight = 0;
		int rightHeight = 0;

		if(IsBalanceCore(Root->left,leftHeight) == false)
		{
			return false;
		}

		if(IsBalanceCore(Root->right,rightHeight) == false)
		{
			return false;
		}

		Height = leftHeight>rightHeight ? leftHeight+1 : rightHeight+1;

		return abs(leftHeight-rightHeight)<2;
	}

	bool IsBalanced_Solution(TreeNode* pRoot) 
	{
		int Height = 0;
		return IsBalanceCore(pRoot,Height);
	}
};

void TestBalance()
{
	Solution s;
	TreeNode* root = new TreeNode(1);
	TreeNode* rleft = new TreeNode(2);
	TreeNode* rright = new TreeNode(3);
	TreeNode* right = new TreeNode(4);
	//TreeNode* left = new TreeNode(4);

	root->left = rleft;
	root->right = rright;
	rleft->right = right;
	//right->left = left;

	cout<<s.IsBalanced_Solution(root)<<endl;
}

int main()
{
	TestBalance();

	system("pause");
	return 0;
}


