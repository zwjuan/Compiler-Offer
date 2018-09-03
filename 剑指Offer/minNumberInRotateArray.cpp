
#include <iostream>
#include<vector>
using namespace std;

//旋转数组的最小数字
//思路1：直接遍历查找，时间复杂度为O(n)
//思路2：使用二分查找思想，
//注意点：1.如果旋转前0个，返回第一个元素  2.当三个位置（index1、index2、midIndex）的值相等时，需要使用顺序查找
       

class Solution {
public:

	int OrderFind(vector<int> rotateArray,int index1, int index2)
	{
		//寻找最小的元素
		int result = rotateArray[index1];

		for(int i=index1+1; i<index2; ++i)
		{
			if(rotateArray[i] < result)
			{
				result = rotateArray[i];
			}
		}

		return result;
	}

    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size() == 0)
        {
            return 0;
        }
        //只有一个元素，直接返回
		if(rotateArray.size() == 1)
		{
			return rotateArray[0];
		}

		int index1 = 0;
		int index2 = rotateArray.size()-1;
		int midIndex = index1;
		while(rotateArray[index1] >= rotateArray[index2])
		{
			//只有两个元素，且第2个小于第一个返回第2个
			if(index2-index1 == 1) 
			{
				midIndex = index2;
				break;
			}

			midIndex = index1+((index2-index1)>>1);

			//如果index1、index2、midIndex所指元素相等的话，使用顺序查找
			if(rotateArray[index1] == rotateArray[index2] && rotateArray[index2] == rotateArray[midIndex])
			{
				return OrderFind(rotateArray,index1, index2);
			}

			if(rotateArray[midIndex] >= rotateArray[index1])
			{
				index1 = midIndex;
			}
			else if(rotateArray[midIndex] <= rotateArray[index2])
			{
				index2 = midIndex;
			}
		}
		return rotateArray[midIndex];
    }
};

void TestRotateArray()
{
	int a[] = {3,4,5,1,2};
	vector<int> v(a,a+sizeof(a)/sizeof(a[0]));
	Solution s;
	cout<<s.minNumberInRotateArray(v)<<endl;

}