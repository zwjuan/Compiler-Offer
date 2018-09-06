#include"comm.h"

//���������������г��ֵĴ���
//˼·��ʹ�ö��ֲ��ң��ҵ������������еĿ�ʼλ�úͽ���λ��
class Solution {
public:
	int GetFist(vector<int> data,int k)
	{
		int start = 0;
		int end = data.size()-1;
		while(start <= end)
		{
			int mid = start+((end-start)>>1);
			if(k > data[mid])
			{
				start = mid+1;
			}
			else if(k < data[mid])
			{
				end = mid-1;
			}
			else 
			{
				//���ڣ� �ҵ�һ��λ��
				if((mid > 0  && data[mid-1] != k) ||(mid == 0))
				{
					return mid;
				}
				else
				{
					end = mid-1;
				}
			}
		}
		return -1; //û�ҵ�����-1
	}

	int GetLast(vector<int> data,int k)
	{
		int start = 0;
		int end = data.size()-1;
		while(start <= end)
		{
			int mid = start+((end-start)>>1);
			if(k > data[mid])
			{
				start = mid+1;
			}
			else if(k < data[mid])
			{
				end = mid-1;
			}
			else 
			{
				//���ڣ� �ҵ�һ��λ��
				if((mid < data.size()-1  && data[mid+1] != k) ||(mid == data.size()-1))
				{
					return mid;
				}
				else
				{
					start = mid+1;
				}
			}

		}
		return -1;// û���ҵ�����0��
	}

    int GetNumberOfK(vector<int> data ,int k) {
		int number = 0;

		if(data.size() > 0)
		{
			int first = GetFist(data,k);
			int last = GetLast(data,k);

			if(first > -1 && last >-1)
			{
				number = last - first +1;
			}
		}
		return number;
    }
};


void TestGetNumber()
{
	int a[] = {1,3,3,3,3,4,5};
	vector<int> v(a,a+sizeof(a)/sizeof(a[0]));

	Solution s;
	cout<<s.GetNumberOfK(v,2)<<endl;
}
