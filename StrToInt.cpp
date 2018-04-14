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

//�˺��������ж�һЩ������� 
int StrToInt(const char* str) 
{
	g_status = kInValid; //��Ч����Ƚ϶࣬��Ĭ�ϳ�ʼ��Ϊ��Ч�� 
	long long num = 0;
	if(str != NULL && *str != '\0') //�����ַ���ΪNULLָ�룬�����ַ���Ϊ���ַ� 
	{
		bool minus = false; //����������

		while(*str == ' ')  //��ǰ���ǿո��ַ��Ĵ���
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

		if(*str != '\0') //�Ե���"+" "-"�ŵĴ��� 
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

			//�ж��Ƿ����
			if((flag == 1 && num*flag > 0x7FFFFFFF) 
				|| (flag == -1 && num*flag < (signed int)0x80000000))   //����ж���������� 
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

	if(* digit == '\0') //�Ƿ��ж��ַ�������� 
	{
		g_status = kValid;
	}

	return num*flag; 
}

int main()
{
	//�������� 
	cout<<StrToInt(NULL)<<endl; //��ָ��
	cout<<StrToInt("")<<endl; //���ַ���
	cout<<StrToInt("  ")<<endl;//���пո���ַ�
	cout<<StrToInt("+")<<endl ; //�����Ŵ��� 
	cout<<StrToInt("-")<<endl;
	cout<<StrToInt("+100")<<endl;
	cout<<StrToInt("-100")<<endl;
	cout<<StrToInt("+0")<<endl; //�������ŵ��ַ�0 
	cout<<StrToInt("0")<<endl;
	cout<<StrToInt("-0")<<endl;  
	cout<<StrToInt("   100")<<endl; //ǰ�溬�пո���ַ��� 
	cout<<StrToInt("   abc")<<endl;
	cout<<StrToInt("123")<<endl;
	cout<<StrToInt("+2147483647")<<endl; //����ж� ��Ч�����������
	cout<<StrToInt("+2147483648")<<endl;  
	cout<<StrToInt("-2147483647")<<endl;  
	cout<<StrToInt("-2147483648")<<endl;  
	cout<<StrToInt("-2147483648")<<endl;  
	cout<<StrToInt("-2147483649")<<endl;  

	system("pause");
	return 0;
}