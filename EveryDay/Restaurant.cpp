/*
	ĳ�͹���n�����ӣ�ÿ��������һ��������a �����ɵ���������� 
	��m�����ˣ�ÿ����������������:b������cԤ�����ѽ� 
	�ڲ�����ƴ��������£���ʵ��һ���㷨ѡ������һ���ֿ��ˣ�
	ʹ����Ԥ�����ѽ�����
	ע�������ѽ����ܳ����������ֵ��
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
		//��ʼ��table
		table.resize(n);
		for(int i=0; i<n; ++i)
		{
			cin>>table[i];
		}

		//������������
		sort(table.begin(),table.end());
		
		//��ʼ��custom
		for(int i=0; i<m; ++i)
		{
			int b,c;
			cin>>b>>c;

			if(b <= table[n-1])
			{
				vc.push_back(Customer(b,c));
			}
		}

		//��Customer�������ѽ���������
		sort(vc.begin(),vc.end(),Comp);

		long long sum = 0;
		//���������
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