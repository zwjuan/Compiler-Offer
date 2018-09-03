#include<iostream>
#include<string>
#include<vector>
using namespace std;


class Printer {
public:
	//顺时针打印矩阵
    vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) 
	{
		vector<int> ret;
        if(mat.size() <=0  || (n<=0 && m<=0))
        {
            return ret;
        }
		
		int left = 0;
		int right = m-1;
		int top = 0;
		int btm = n-1;
		while(left <= right && top <= btm)
		{
			//从左到右
			for(int i=left; i<=right; ++i)
			{
				ret.push_back(mat[top][i]);
			}

			//从上下
			if(top < btm)//top == btm说明只有一行
			{
				for(int i=top+1; i<=btm; i++)
				{
					ret.push_back(mat[i][right]);
				}
			}

			//从右往左
			if(top<btm && left<right)
			{
				for(int i=right-1; i>=left; --i)
				{
					ret.push_back(mat[btm][i]);
				}
			}

			//从下到上
			if(top+1 < btm && left < right)
			{
				for(int i=btm-1; i>= top+1; --i)
				{
					ret.push_back(mat[i][left]);
				}
			}
			left--;
			right--;
			top++;
			btm--;
		}
		
		return ret;
    }
};

void  TestPrint()
{
	vector<vector<int> > v;
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	vector<int> v2;
	v2.push_back(3);
	v2.push_back(4);
	v2.push_back(5);
	v.push_back(v1);
	v.push_back(v2);

	Printer p;
	vector<int> ret = p.clockwisePrint(v,3,3);

}

int main()
{
	TestPrint();

	system("pause");
	return 0;
}