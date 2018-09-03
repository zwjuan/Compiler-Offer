#include<iostream>
#include<string>
#include<vector>
using namespace std;

//�����е������
class AntiOrder {
public:
	//�����е������
	//˼·���Ȱ�����ָ��������飬Ȼ�����ù鲢˼�룬ͳ�Ƴ��������е�����ԡ�
	int _count(vector<int> A,int left, int right ,vector<int>& tmp)
	{
		if(left >= right)//ֻ��һ��Ԫ��ʱ��ֱ�ӽ��п���
		{
			return 0;
		}
		//����
		int mid = left+((right-left)>>1);
		int leftcount = _count(tmp,left,mid,A);//ʹ�øı���������н����ж�
		int rightcount = _count(tmp,mid+1,right,A);

		//�ϲ�
		int i=mid; //i��ʼ��Ϊǰ������һ�����ֵ��±�
		int j=right; //j��ʼ��Ϊ�������һ�����ֵ��±�
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

		while(i >= left) //����ǰ���ʣ�µ�Ԫ��
		{
			tmp[index --] = A[i--];
		}

		while(j >= mid+1) //��������ʣ�µ�Ԫ��
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