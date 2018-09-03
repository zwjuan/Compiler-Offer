
#include <iostream>
#include<vector>
using namespace std;

//��ת�������С����
//˼·1��ֱ�ӱ������ң�ʱ�临�Ӷ�ΪO(n)
//˼·2��ʹ�ö��ֲ���˼�룬
//ע��㣺1.�����תǰ0�������ص�һ��Ԫ��  2.������λ�ã�index1��index2��midIndex����ֵ���ʱ����Ҫʹ��˳�����
       

class Solution {
public:

	int OrderFind(vector<int> rotateArray,int index1, int index2)
	{
		//Ѱ����С��Ԫ��
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
        //ֻ��һ��Ԫ�أ�ֱ�ӷ���
		if(rotateArray.size() == 1)
		{
			return rotateArray[0];
		}

		int index1 = 0;
		int index2 = rotateArray.size()-1;
		int midIndex = index1;
		while(rotateArray[index1] >= rotateArray[index2])
		{
			//ֻ������Ԫ�أ��ҵ�2��С�ڵ�һ�����ص�2��
			if(index2-index1 == 1) 
			{
				midIndex = index2;
				break;
			}

			midIndex = index1+((index2-index1)>>1);

			//���index1��index2��midIndex��ָԪ����ȵĻ���ʹ��˳�����
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