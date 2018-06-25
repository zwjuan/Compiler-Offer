/*
	题目：后序非递归遍历二叉树
*/

#include<iostream>
#include<vector>
#include<stack>
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
	vector<int> postorderTraversal(TreeNode *root) 
	{
		vector<int> ret;
		stack<TreeNode*> s;
		TreeNode* cur = root;
		TreeNode* prev = NULL;
		while(cur || !s.empty())
		{
			while(cur)
			{
				s.push(cur);
				cur = cur->left;
			}

			TreeNode* top = s.top();

			if(top->right == NULL || top->right == prev)
			{
				ret.push_back(top->val);
				s.pop();
				prev = top;
			}
			else
			{
				cur = top->right;
			}
		}
		return ret;
	}
};

void TestPostOrder()
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

	vector<int> v = s.postorderTraversal(root);
	for(size_t i=0; i<v.size(); ++i)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}


int main()
{
	TestPostOrder();

	system("pause");
	return 0;
}