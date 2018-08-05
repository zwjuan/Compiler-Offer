/*
	某餐馆有n张桌子，每张桌子有一个参数：a 可容纳的最大人数； 
	有m批客人，每批客人有两个参数:b人数，c预计消费金额。 
	在不允许拼桌的情况下，请实现一个算法选择其中一部分客人，
	使得总预计消费金额最大
	注：总消费金额可能超过整形最大值。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Customer
{
	Customer(const int& b, const int& c)
		:_b(b)
		,_c(c)
	{}

	int _b;
	int _c;
};

bool Comp(const Customer& c1, const Customer& c2)
{
	return (c1._c > c2._c);
}

int main()
{
	vector<int> table;
	vector<Customer> vc;
	int n, m;
	while(cin>> n>> m)
	{
		//初始化table
		table.resize(n);
		for(int i=0; i<n; ++i)
		{
			cin>>table[i];
		}

		//进行排序（升序）
		sort(table.begin(),table.end());
		
		//初始化custom
		for(int i=0; i<m; ++i)
		{
			int b,c;
			cin>>b>>c;

			if(b <= table[n-1])
			{
				vc.push_back(Customer(b,c));
			}
		}

		//对Customer按照消费金额，进行排序
		sort(vc.begin(),vc.end(),Comp);

		long long sum = 0;
		//求最大消费
		for(int i=0; i<vc.size(); ++i)
		{
			for(int j=0; j<n; ++j)
			{
				if(vc[i]._b <= table[j] && table[j]!= -1)
				{
					sum += vc[i]._c;
					table[j] = -1;
					break;
				}
			}
		}
		cout<< sum<<endl;
	}
    
    return 0;
}