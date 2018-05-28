/*
	������42����ת����˳�� VS ����ת�ַ���
	��Ŀ1������һ��Ӣ�ľ��ӣ���ת�����е��ʵ�˳�򣬵��������ַ���˳�򲻱䡣�����ź���ͨ��ĸһ������
	���磺�����ַ�����I am a student.��,�������student. a am I��
	˼·��1.�ȷ�ת�������� 2.��ת�����е�ÿ������

	��Ŀ2���ַ���������ת�����ǰ��ַ���ǰ������ɸ��ַ�ת�Ƶ��ַ�����β����
	�붨��һ������ʵ���ַ�������ת�����Ĺ��ܡ����������ַ�����abcdefg��������2��
	�ú�������������ת2λ�õ��Ľ����cdefgab��.
	˼·���Ȳ�����ת��������ת

*/

#include <iostream>
using namespace std;

void Reverse(char* pBegin, char* pEnd)
{
	if(pBegin == NULL || pEnd == NULL)
	{
		return;
	}

	while(pBegin < pEnd)
	{
		char temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;

		pBegin++;
		pEnd--;
	}
}

char* ReverseSentence(char* pData)
{
	if(pData == NULL)
	{
		return NULL;
	}

	char* pBegin = pData;
	char* pEnd = pData;
	while(*pEnd != '\0')
	{
		pEnd++;
	}
	pEnd--;

	//��ת��������
	Reverse(pBegin,pEnd);

	//��ת�����е�ÿ������
	pBegin = pEnd = pData;
	while(*pBegin != '\0')
	{
		if(*pBegin == ' ')
		{
			pBegin++;
			pEnd++;
		}
		else if(*pEnd == ' ' || *pEnd == '\0')
		{
			Reverse(pBegin,--pEnd);
			pBegin = ++pEnd;
		}
		else
		{
			pEnd++;
		}
	}
	return pData;
}

char* LeftRotateString(char* pStr, int n)//n��ʾ������λ
{
	if(pStr != NULL)
	{
		int len = strlen(pStr);
		if(len>0 && n>0 && n<len)
		{
			char* pFirstStart = pStr;
			char* pFirstEnd = pStr + n - 1;
			char* pSecondStart = pStr+n;
			char* pSecondEnd = pStr+len-1;

			//��ת�ַ�����ǰ���n���ַ�
			Reverse(pFirstStart,pFirstEnd);
			//��ת�����ַ���
			Reverse(pSecondStart,pSecondEnd);
			//��ת�����ַ���
			Reverse(pFirstStart,pSecondEnd);
		}
	}
	
	return pStr;
}

void TestReverseSentence()
{
	//char arr[] = "I am a student."
	//char arr[] = "";//���ַ���

	char arr[] = "   ";//�ո�
	cout<<ReverseSentence(arr)<<endl;
}

void TestLeftRotateString()
{
	char arr[] = "abcdef";
	cout<<LeftRotateString(arr,0)<<endl;//����0
	cout<<LeftRotateString(arr,2)<<endl;
//	cout<<LeftRotateString(arr,6)<<endl;//n=len
//	cout<<LeftRotateString(arr,7)<<endl;//n = len+1
}

int main()
{
	/*TestReverseSentence();*/
	TestLeftRotateString();
	system("pause");
	return 0;
}
