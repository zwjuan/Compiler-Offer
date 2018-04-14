#include<iostream>
using namespace std;

long long StrToIntCore(const char* digit,bool minus);
int StrToInt(const char* str) ;

enum Status
{
	kValid = 0,
	kInValid
};

int g_status = kValid; 

//此函数用来判断一些特殊情况 
int StrToInt(const char* str) 
{
	g_status = kInValid; //无效情况比较多，先默认初始化为无效的 
	long long num = 0;
	if(str != NULL && *str != '\0') //输入字符串为NULL指针，输入字符串为空字符 
	{
		bool minus = false; //正数、负数

		while(*str == ' ')  //对前面是空格字符的处理
		{
			str++; 
		}

		if(*str == '+')
		{
			str++;
		}
		else if(*str == '-')
		{
			minus = true;
			str++;
		} 

		if(*str != '\0') //对单独"+" "-"号的处理 
		{
			num = StrToIntCore(str, minus); 
		} 

	}
	return (int)num;
}

long long StrToIntCore(const char* digit,bool minus)
{
	long long num = 0;
	int flag = minus ? -1 : 1;

	while(*digit != '\0')
	{
		if(*digit >= '0' && *digit <= '9')
		{
			num = num*10 + *digit - '0';

			//判断是否溢出
			if((flag == 1 && num*flag > 0x7FFFFFFF) 
				|| (flag == -1 && num*flag < (signed int)0x80000000))   //如何判断溢出？？？ 
			{
				num = 0;
				break; 
			} 
			digit ++;
		}
		else
		{
			num = 0;
			break; 
		}

	}

	if(* digit == '\0') //是否判断字符串的最后 
	{
		g_status = kValid;
	}

	return num*flag; 
}

int main()
{
	//测试用例 
	cout<<StrToInt(NULL)<<endl; //空指针
	cout<<StrToInt("")<<endl; //空字符串
	cout<<StrToInt("  ")<<endl;//含有空格的字符
	cout<<StrToInt("+")<<endl ; //正负号处理 
	cout<<StrToInt("-")<<endl;
	cout<<StrToInt("+100")<<endl;
	cout<<StrToInt("-100")<<endl;
	cout<<StrToInt("+0")<<endl; //带正负号的字符0 
	cout<<StrToInt("0")<<endl;
	cout<<StrToInt("-0")<<endl;  
	cout<<StrToInt("   100")<<endl; //前面含有空格的字符串 
	cout<<StrToInt("   abc")<<endl;
	cout<<StrToInt("123")<<endl;
	cout<<StrToInt("+2147483647")<<endl; //溢出判断 有效的最大正整数
	cout<<StrToInt("+2147483648")<<endl;  
	cout<<StrToInt("-2147483647")<<endl;  
	cout<<StrToInt("-2147483648")<<endl;  
	cout<<StrToInt("-2147483648")<<endl;  
	cout<<StrToInt("-2147483649")<<endl;  

	system("pause");
	return 0;
}