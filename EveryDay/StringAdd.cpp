#include <iostream>
#include <string>
using namespace std;

//无线OSS－高精度整数加法
//分情况：
//1.	两个正号，去掉正号，两个数直接进行相加
//	2.	两个负号，去掉负号两个数进行相加，最后加上负号
//	3.	一正一负，补位，然后比较两个数的大小，若正数大于负数，用整数减去负数，结果为正数，否则结果为负数。

string AddCore(string num1,string num2)//两数相加
{
	string res = "";

	//先补位，然后进行相加
	if(num1.size() > num2.size())
	{
		num2 = string(num1.size() - num2.size(),'0') + num2;
	}
	else
	{
		num1 = string(num2.size()-num1.size(),'0')+num1;
	}

	//相加
	int carry = 0;//进位
	for(int i=num1.size()-1; i>=0; --i)
	{
		char tmp = (num1[i]-'0' +  num2[i]-'0'+carry)%10 + '0';
		res = tmp + res;//开始的数字应该存在最低位
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

	if(isdigit(num1[0]) && isdigit(num2[0])) //两正
	{
		return AddCore(num1, num2);
	}
	else if(!isdigit(num1[0]) && !isdigit(num2[0])) //两负
	{
		num1 = num1.substr(1);
		num2 = num2.substr(1);

		return '-'+AddCore(num1,num2);
	}
	else if(isdigit(num1[0]) && !isdigit(num2[0])) //一正数一负数
	{
		num2 = num2.substr(1);
		//补位然后比较两个数的大小
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
	else //一负一正
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
