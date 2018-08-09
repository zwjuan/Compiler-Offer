
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
	//思路1：
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

	//思路2：//需要两个变量：一个变量表示在当前层中还没有打印的结点数。另一个变量表示下一层结点的数目
	vector<vector<int> > Print2(TreeNode* pRoot) 
	{

		queue<TreeNode*> q;
		vector<vector<int> > ret;
		if(pRoot == NULL)
		{
			return ret;
		}

		q.push(pRoot);
		int nextlevel =0;
		int toBePrint = 1; 
		vector<int> v;
		while(!q.empty())
		{
			TreeNode* front = q.front();
			v.push_back(front->val);
			q.pop();
			--toBePrint;

			if(front->left != NULL)
			{
				q.push(front->left);
				++nextlevel;
			}

			if(front->right != NULL)
			{
				q.push(front->right);
				++nextlevel;
			}

			if(toBePrint == 0)
			{
				ret.push_back(v);
				toBePrint = nextlevel;
				nextlevel = 0;
				v.clear();
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