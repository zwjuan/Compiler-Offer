#pragma once

/*
	题目：数组中出现次数超过一半的数字

	分析：
	a.排序 排序之后位于数组中间的数字一定就是那个出现次数超过数组长度一半的数字。时间复杂度为O(nlogN).
	b.利用排序算法思想，找中位数，此中位数为要找的数，（典型递归问题）。
	c.我们可以考虑在遍历数组时候保存两个值：一个是数组中的一个数字，一个是次数。当我们遍历到下一个数字的时候，如果下一个数字和我们之前保存的数字相同，则次数加1；如果下一个数字和我们之前保存的数字不同，则次数减1.如果次数为零，我们需要保存下一个数字，并把次数设为1，由于我们要找的数字出现的次数比其他所有数字出现的数字之和要多，那么要找的数字肯定是最后一次把次数设为1时对应的数字。

*/

#include <iostream>
using namespace std;

int Partition(int* a, int begin, int end)
{
	int left = begin, right = end;
	int key = a[right];

	while(begin<end)
	{
		while(begin<end && a[begin]<=key) //左边找大于key的值
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
//方法1：利用快排进行排序，则排序后中间的数为数字中出现次数超过一半的数字  时间复杂度为O(nlogN)
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
	cout<<"排序后:"<<" ";
	for(size_t i=0; i<len; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	cout<<"超过数组一半的数字为:"<<" ";
	cout<<arr[len/2]<<endl;;	
}

//方法2：利用排序思想，但只要找到中位数就停止  时间复杂度为O(n)
//注意：1.开始应检查输入的合法性 CheckInvalidArray()
//		2.CheckMoreThanhalf() 检查数组中出现频率高的数字是否超过数组的一半
bool CheckInvalidArray(int* nums, int len)
{
	if(nums == NULL || len<=0)
	{
		return true; //返回true说明此数组无效
	}
	return false;
}

bool CheckMoreThanHalf(int* nums, int len, int half)
{
	//通过遍历数组判断half是否是出现超过数组一半的数字
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

	//判断中间元素的下标
	int mid = len>>2;
	int begin = 0;
	int end = len-1;
	int div = Partition(nums,begin,end);
	//用递归或循环查找中间的数（这里采用循环）
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

	//检查中间元素是否有效
	if(!CheckMoreThanHalf(nums,len,ret))
	{
		ret = 0; //找不到返回0
	}

	return ret;
}

void TestMoreThanHalf()
{
	int arr[] = {1,2,3,2,2,2,5,4,2};
	int len = sizeof(arr)/sizeof(arr[0]);
	cout<<MoreThanHalfNum(arr,len)<<endl;
}

//方法3：在遍历数组时，保存两个值，一个是数组的一个数字，一个是次数

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
		ret = 0; //找不到返回0
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