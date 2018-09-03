#include<iostream>
#include<string>
#include<vector>
using namespace std;

//数组中的逆序对
class AntiOrder {
public:
	//数组中的逆序对
	//思路：先把数组分隔成子数组，然后利用归并思想，统计出子数组中的逆序对。
	int _count(vector<int> A,int left, int right ,vector<int>& tmp)
	{
		if(left >= right)//只有一个元素时，直接进行拷贝
		{
			return 0;
		}
		//划分
		int mid = left+((right-left)>>1);
		int leftcount = _count(tmp,left,mid,A);//使用改变的数组序列进行判断
		int rightcount = _count(tmp,mid+1,right,A);

		//合并
		int i=mid; //i初始化为前半段最后一个数字的下标
		int j=right; //j初始化为后半段最后一个数字的下标
		int index = right;
		int count = 0;
		while(i>=left && j>= mid+1)
		{
			if(A[i] > A[j])
			{
				count += j-mid;
				tmp[index--] = A[i--];
			}
			else
			{
				tmp[index--] = A[j--];
			}
		}

		while(i >= left) //拷贝前半段剩下的元素
		{
			tmp[index --] = A[i--];
		}

		while(j >= mid+1) //拷贝后半段剩下的元素
		{
			tmp[index --] = A[j--];
		}

		return leftcount+rightcount+count;
	}

    int count(vector<int> A, int n) 
	{
        if(A.size() <=0 || n<=0)
		{
			return 0;
		}

		vector<int> tmp(A);
		int count =  _count(A,0, n-1,tmp);
		
		return count;
    }
};

void TestAntiOrder()
{
	AntiOrder A;
	int a[] = {7,5,6,4};
	int len = sizeof(a)/sizeof(a[0]);
	vector<int> v(a,a+len);
	int count = A.count(v,len);
}

int main()
{
	TestAntiOrder();

	system("pause");
	return 0;
}