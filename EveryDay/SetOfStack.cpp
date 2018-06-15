/*
	��Ŀ��ʵ��һ�����ݽṹsetOfStacks,�ɶ��ջ ��ɣ�����ÿ��ջ�Ĵ�СΪsize
	��ǰһ��ջ����ʱ���½�һ��ջ��
	����һ����������int[][2]ope(C++ΪǶ��vector)��ÿ�������ĵ�һ��������������ͣ�
	��Ϊ1����Ϊpush��������һ����ӦΪpush�����֣���Ϊ2����Ϊpop��������һ���������塣
	�뷵��һ��int[][],Ϊ������в������setOfStacks,˳��ӦΪ���µ��ϣ�
	ĬȻ��ʼ��setOfStackΪ��
*/

#include<iostream>
#include <vector>
using namespace std;

vector<vector<int> > setOfStacks(vector<vector<int> > ope, int size) //size��ʾÿ��ջ�Ĵ�С
{
	// write code here
	vector<vector<int>> ret;
	vector<int> stack;
	for(size_t i=0; i<ope.size();++i)
	{
		if(ope[i][0] == 1) //push
		{
			//���ж�ret���Ƿ�����
			if(ret.size() == 0 || ret[ret.size()-1].size() == size) //retΪNULL��ret��ջ������
			{
				if(stack.size() == size)
				{
					ret.push_back(stack);
					stack.clear();
				}
				stack.push_back(ope[i][1]);
			}
			else
			{
				//ret��ջ��û����ʱ
				ret[ret.size()-1].push_back(ope[i][1]);
			}
			
		}
		else  //pop
		{
			if(!stack.empty())
			{
				stack.pop_back();
			}
			else
			{
				if(!ret.empty())
				{
					//����retջ��
					ret[ret.size()-1].pop_back();
					//�ж�ջ���Ƿ�ΪNULL��ΪNULL�򵯳�
					if(ret[ret.size()-1].empty())
					{
						ret.pop_back();
					}
				}
			}
		}
	}

	if(!stack.empty())
	{
		ret.push_back(stack);
	}
	return ret;
}

void TestStack()
{
	vector<vector<int> > ope; //ѹ��Ԫ��Ϊ 0��1��2  ����Ԫ��Ϊ2
	ope.resize(9);
	
	for(size_t i=0; i<6; ++i)
	{
		ope[i].resize(2);
		ope[i][0] = 1;
		ope[i][1] = i;
	}
	ope[6].resize(2);
	ope[6][0] = 2; //

	for(size_t i=7; i<9; ++i) //4 ,5 ����5
	{
		ope[i].resize(2);
		ope[i][0] = 1;
		ope[i][1] = i;
	}
	
	vector<vector<int> > v = setOfStacks(ope,7);
}

int main()
{

	TestStack();

	system("pause");
	return 0;
}