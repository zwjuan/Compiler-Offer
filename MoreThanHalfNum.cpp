#pragma once

/*
	��Ŀ�������г��ִ�������һ�������

	������
	a.���� ����֮��λ�������м������һ�������Ǹ����ִ����������鳤��һ������֡�ʱ�临�Ӷ�ΪO(nlogN).
	b.���������㷨˼�룬����λ��������λ��ΪҪ�ҵ����������͵ݹ����⣩��
	c.���ǿ��Կ����ڱ�������ʱ�򱣴�����ֵ��һ���������е�һ�����֣�һ���Ǵ����������Ǳ�������һ�����ֵ�ʱ�������һ�����ֺ�����֮ǰ�����������ͬ���������1�������һ�����ֺ�����֮ǰ��������ֲ�ͬ���������1.�������Ϊ�㣬������Ҫ������һ�����֣����Ѵ�����Ϊ1����������Ҫ�ҵ����ֳ��ֵĴ����������������ֳ��ֵ�����֮��Ҫ�࣬��ôҪ�ҵ����ֿ϶������һ�ΰѴ�����Ϊ1ʱ��Ӧ�����֡�

*/

#include <iostream>
using namespace std;

int Partition(int* a, int begin, int end)
{
	int left = begin, right = end;
	int key = a[right];

	while(begin<end)
	{
		while(begin<end && a[begin]<=key) //����Ҵ���key��ֵ
		{
			++begin;
		}
		while(begin<end && a[end]>=key)
		{
			--end;
		}
		swap(a[begin], a[end]);
	}
	swap(a[begin],a[right]);
	return begin;

}
//����1�����ÿ��Ž���������������м����Ϊ�����г��ִ�������һ�������  ʱ�临�Ӷ�ΪO(nlogN)
void QuickSort(int* a, int begin, int end)
{
	if(begin >= end)
	{
		return ;
	}

	int left = begin, right = end;
	int div=Partition(a,begin,end);
	

	QuickSort(a,left,div-1);
	QuickSort(a,div+1,right);
}

void TestQuickSort()
{
	int arr[] = {1,2,3,2,2,2,5,4,2};
	int len = sizeof(arr)/sizeof(arr[0]);

	QuickSort(arr,0,len-1);
	cout<<"�����:"<<" ";
	for(size_t i=0; i<len; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	cout<<"��������һ�������Ϊ:"<<" ";
	cout<<arr[len/2]<<endl;;	
}

//����2����������˼�룬��ֻҪ�ҵ���λ����ֹͣ  ʱ�临�Ӷ�ΪO(n)
//ע�⣺1.��ʼӦ�������ĺϷ��� CheckInvalidArray()
//		2.CheckMoreThanhalf() ��������г���Ƶ�ʸߵ������Ƿ񳬹������һ��
bool CheckInvalidArray(int* nums, int len)
{
	if(nums == NULL || len<=0)
	{
		return true; //����true˵����������Ч
	}
	return false;
}

bool CheckMoreThanHalf(int* nums, int len, int half)
{
	//ͨ�����������ж�half�Ƿ��ǳ��ֳ�������һ�������
	int times = 0;
	for(int i=0; i<len; i++)
	{
		if(nums[i] = half)
		{
			++times;
		}
	}

	if((times*2 <= len))
	{
		return false;
	}
	return true;
}

int MoreThanHalfNum(int* nums, int len)
{
	if(CheckInvalidArray(nums,len))
	{
		return 0;
	}

	//�ж��м�Ԫ�ص��±�
	int mid = len>>2;
	int begin = 0;
	int end = len-1;
	int div = Partition(nums,begin,end);
	//�õݹ��ѭ�������м�������������ѭ����
	while(div != mid)
	{
		if(div < mid)
		{
			begin = div + 1; 
			div = Partition(nums, begin, end);
		}
		else //div>mid
		{
			end = div-1;
			div = Partition(nums, begin, end);
		}
	}
	int ret = nums[mid];

	//����м�Ԫ���Ƿ���Ч
	if(!CheckMoreThanHalf(nums,len,ret))
	{
		ret = 0; //�Ҳ�������0
	}

	return ret;
}

void TestMoreThanHalf()
{
	int arr[] = {1,2,3,2,2,2,5,4,2};
	int len = sizeof(arr)/sizeof(arr[0]);
	cout<<MoreThanHalfNum(arr,len)<<endl;
}

//����3���ڱ�������ʱ����������ֵ��һ���������һ�����֣�һ���Ǵ���

int MoreThanHalfNum3(int* nums, int len)
{
	if(CheckInvalidArray(nums,len))
	{
		return 0;
	}

	int ret = nums[0];
	int times = 1;

	for(size_t i=1; i<len; i++)
	{
		if(times == 0)
		{
			ret = nums[i];
			times = 1;
		}
		else if(nums[i] == ret)
		{
			++times;
		}
		else
		{
			--times;
		}
	}

	if(!CheckMoreThanHalf(nums,len,ret))
	{
		ret = 0; //�Ҳ�������0
	}

	return ret;
}

void TestMoreThanHalf3()
{
	int arr[] = {1,2,3,2,2,2,5,4,2};
	int len = sizeof(arr)/sizeof(arr[0]);
	cout<<MoreThanHalfNum3(arr,len)<<endl;
}

int main()
{
	//TestQuickSort();
	
	//TestMoreThanHalf();

	TestMoreThanHalf3();
	system("pause");
	return 0;
}