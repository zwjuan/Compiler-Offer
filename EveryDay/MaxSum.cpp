#include <iostream>
#include <vector>
using namespace std;

//1. 最大连续数列和
class MaxSum {
public:
	int getMaxSum(vector<int> A, int n) 
	{
		if(n <= 0)
		{
			return 0;
		}

		int CurSum = 0; //记录当前最大和
		int Sum = 0x80000000; //用于记录最大值
		for(int i=0; i<n; ++i)
		{
			if( CurSum <=0)
			{
				CurSum = A[i];
			}
			else
			{
				CurSum += A[i];
			}

			if(CurSum > Sum)
			{
				Sum = CurSum;
			}
		}

		return Sum ;
	}
};

int main()
{
	MaxSum m;
	//int a[] = {-56,7,-129,-71,3,-119};
	int a[] = {-1,-2};
	vector<int> v(a,a+sizeof(a)/sizeof(a[0]));
	cout<<m.getMaxSum(v,sizeof(a)/sizeof(a[0]))<<endl;

	return 0;
}