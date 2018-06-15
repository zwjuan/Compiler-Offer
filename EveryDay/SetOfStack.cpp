/*
	题目：实现一种数据结构setOfStacks,由多个栈 组成，其中每个栈的大小为size
	当前一个栈填满时，新建一个栈。
	给定一个操作序列int[][2]ope(C++为嵌套vector)，每个操作的第一个数代表操作类型，
	若为1，则为push操作，后一个数应为push的数字；若为2，则为pop操作，后一个数无意义。
	请返回一个int[][],为完成所有操作后的setOfStacks,顺序应为从下到上，
	默然初始的setOfStack为空
*/

#include<iostream>
#include <vector>
using namespace std;

vector<vector<int> > setOfStacks(vector<vector<int> > ope, int size) //size表示每个栈的大小
{
	// write code here
	vector<vector<int>> ret;
	vector<int> stack;
	for(size_t i=0; i<ope.size();++i)
	{
		if(ope[i][0] == 1) //push
		{
			//先判断ret中是否已满
			if(ret.size() == 0 || ret[ret.size()-1].size() == size) //ret为NULL或ret的栈顶已满
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
				//ret的栈顶没有满时
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
					//弹出ret栈顶
					ret[ret.size()-1].pop_back();
					//判断栈顶是否为NULL，为NULL则弹出
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
	vector<vector<int> > ope; //压入元素为 0、1、2  弹出元素为2
	ope.resize(9);
	
	for(size_t i=0; i<6; ++i)
	{
		ope[i].resize(2);
		ope[i][0] = 1;
		ope[i][1] = i;
	}
	ope[6].resize(2);
	ope[6][0] = 2; //

	for(size_t i=7; i<9; ++i) //4 ,5 弹出5
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