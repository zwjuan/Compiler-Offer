/*
	题目：双栈排序
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> twoStacksSort(vector<int> numbers) 
{
	if(numbers.size() <= 1 )
	{
		return numbers;
	}
	vector<int>  ret;
	ret.push_back(numbers.back());
	numbers.pop_back();

	while(numbers.size() >0)
	{
		//将ret中大于numbers.back()的数据弹出，并记录弹出的个数，方便后续插入
		int n=0; //记录弹出的个数
		int temp = numbers.back();
		numbers.pop_back();
		while(temp > ret.back() && !ret.empty())
		{
			numbers.push_back(ret.back());
			ret.pop_back();
			++n;
		}

		ret.push_back(temp);
		while(n--)
		{
			ret.push_back(numbers.back());
			numbers.pop_back();
		}
	}

	return ret;
}

void TestStackSort()
{
	int a[] = {1,2,3,4,5};
	vector<int> num(a,a+sizeof(a)/sizeof(a[0]));
	vector<int> ret = twoStacksSort(num);

}

int main()
{

	TestStackSort();

	system("pause");
	return 0;
}