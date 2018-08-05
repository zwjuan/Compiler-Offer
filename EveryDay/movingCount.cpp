#include <iostream>
using namespace std;

class Solution {
public:
	//计算位置的数值
	int Add(int num)
	{
		int sum = 0;
		while(num)
		{
			sum += num%10;
			num /= 10;
		}
		return sum;
	}

	//检查当前位置是否合法
	bool check(int threshold, int rows, int cols, int i, int j, int* flag)
	{
		//cout<<(i>=0 && i<rows && j>=0 && j<cols)<<endl;
		//cout<<(flag[i*cols+j] == 0 && (Add(i)+Add(j))<= threshold)<<endl;
		
		if( i>=0 && i<rows && j>=0 && j<cols && flag[i*cols+j] == 0 && (Add(i)+Add(j))<= threshold)
		{
			flag[i*cols + j] = 1;

			return true;
		}
		return false;
	}


	//计算最短移动位置
	int moveing(int threshold, int rows, int cols, int i, int j, int* flag)
	{
		int count = 0;
		if(check(threshold,rows,cols, i, j, flag))
		{
			//上、左、下、右
			count = 1+ moveing(threshold,rows,cols, i-1, j, flag)
				+moveing(threshold,rows,cols, i, j-1, flag)
				+moveing(threshold,rows,cols, i+1, j, flag)
				+moveing(threshold,rows,cols, i, j+1, flag);
		}

		return count;
	}

	int movingCount(int threshold, int rows, int cols)
	{
		int num = 0;
		if(threshold <=0 )
		{
			return 0;
		}

		int* flag = new int[rows*cols];
		for(int i=0; i<rows*cols; ++i)
		{
			flag[i] = 0;
		}

		int count = moveing(threshold,rows,cols,0,0,flag);
		return count;
	}
};

int main()
{
	Solution s;
	cout<<s.movingCount(15,10,1)<<endl;

	return 0;
	
}