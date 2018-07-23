#include <iostream>
#include <string>
using namespace std;

//����OSS���߾��������ӷ�
//�������
//1.	�������ţ�ȥ�����ţ�������ֱ�ӽ������
//	2.	�������ţ�ȥ������������������ӣ������ϸ���
//	3.	һ��һ������λ��Ȼ��Ƚ��������Ĵ�С�����������ڸ�������������ȥ���������Ϊ������������Ϊ������

string AddCore(string num1,string num2)//�������
{
	string res = "";

	//�Ȳ�λ��Ȼ��������
	if(num1.size() > num2.size())
	{
		num2 = string(num1.size() - num2.size(),'0') + num2;
	}
	else
	{
		num1 = string(num2.size()-num1.size(),'0')+num1;
	}

	//���
	int carry = 0;//��λ
	for(int i=num1.size()-1; i>=0; --i)
	{
		char tmp = (num1[i]-'0' +  num2[i]-'0'+carry)%10 + '0';
		res = tmp + res;//��ʼ������Ӧ�ô������λ
		carry = (num1[i]-'0' +  num2[i]-'0'+carry)/10;
	}

	if(carry)
		res = '1'+res;

	return res;
}

string SubCore(string num1,string num2)
{
	string ret = "";
	int borrow = 0;
	int i=num1.size()-1;

	for(; i>=0; --i)
	{
		int opt1 = (num1[i]-borrow >= num2[i])? (num1[i]-borrow -'0'): (10+num1[i]-borrow-'0');
		int opt2 = num2[i]-'0';
		char tmp = opt1-opt2+'0';
		ret = tmp+ret;
		borrow = num1[i]-borrow < num2[i];
	}
	while(ret[++i] == '0')
	{}

	ret = ret.substr(i);

	return ret;
}

string Add(string num1, string num2)
{
	if(num1.size() == 0)
	{
		return num2;
	}

	if(num2.size() == 0)
	{
		return num1;
	}

	if(isdigit(num1[0]) && isdigit(num2[0])) //����
	{
		return AddCore(num1, num2);
	}
	else if(!isdigit(num1[0]) && !isdigit(num2[0])) //����
	{
		num1 = num1.substr(1);
		num2 = num2.substr(1);

		return '-'+AddCore(num1,num2);
	}
	else if(isdigit(num1[0]) && !isdigit(num2[0])) //һ����һ����
	{
		num2 = num2.substr(1);
		//��λȻ��Ƚ��������Ĵ�С
		if(num1.size() > num2.size())
		{
			num2 = string(num1.size()-num2.size(),'0') +num2;
		}
		else 
		{
			num1 = string(num2.size()-num1.size(),'0') +num1;
		}

		if(num1 > num2)
		{
			return SubCore(num1,num2);
		}
		else
		{
			return '-' + SubCore(num2,num1);
		}
	}
	else //һ��һ��
	{
		num1 = num1.substr(1);

		if(num1.size() > num2.size())
		{
			num2 = string(num1.size() - num2.size(),'0') + num2;
		}
		else
		{
			num1 = string(num2.size() - num1.size(),'0') + num1;
		}

		if(num1 > num2)
		{
			return '-' + SubCore(num1,num2);
		}
		else
		{
			return SubCore(num1,num2);
		}

	}
}

int main()
{
	string s1,s2;
	while(cin >>s1>>s2)
	{
		cout<<Add(s1,s2)<<endl;
	}
	return 0;
}
