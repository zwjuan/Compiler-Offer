
/*
	把二叉树打印成多行
	描述：从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
*/

#include <iostream>
#include <vector>
#include <queue>
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
	vector<vector<int> > Print(TreeNode* pRoot) 
	{
		vector<vector<int> > ret;
		
		if(pRoot != NULL)
		{
			TreeNode* cur = pRoot;
			queue<TreeNode*> q;
			q.push(cur);

			while( !q.empty())
			{
				vector<int> v;
				int size = q.size(); //记录队列中的元素，及为每一层的元素
				while(size != 0)
				{
					TreeNode* Front = q.front();
					q.pop();
					--size;
					v.push_back(Front->val);

					if(Front->left)
					{
						q.push(Front->left);
					}

					if(Front->right)
					{
						q.push(Front->right);
					}
				}
				ret.push_back(v);
			}
		}

		return ret;
	}
};

void TestPrint()
{
	Solution s;
	TreeNode* root = new TreeNode(1);
	/*TreeNode* rleft = new TreeNode(2);
	TreeNode* rright = new TreeNode(3);
	TreeNode* right = new TreeNode(4);
	root->left = rleft;
	root->right = rright;
	rleft->right = right;*/

	vector<vector<int> > v = s.Print(root);

	for(size_t i=0; i<v.size(); ++i)
	{
		for(size_t j=0; j<v[i].size(); ++j)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	TestPrint();

	system("pause");
	return 0;
}