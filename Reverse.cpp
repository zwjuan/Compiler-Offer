/*
	面试题42：翻转单词顺序 VS 左旋转字符串
	题目1：输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。标点符号和普通字母一样处理。
	例如：输入字符串“I am a student.”,则输出“student. a am I”
	思路：1.先反转整个句子 2.反转句子中的每个单词

	题目2：字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
	请定义一个函数实现字符串左旋转操作的功能。比如输入字符串“abcdefg”和数字2，
	该函数将返回左旋转2位得到的结果“cdefgab”.
	思路：先部分旋转在整体旋转

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

	//反转整个句子
	Reverse(pBegin,pEnd);

	//反转句子中的每个单词
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

char* LeftRotateString(char* pStr, int n)//n表示左旋几位
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

			//翻转字符串的前面的n个字符
			Reverse(pFirstStart,pFirstEnd);
			//翻转后面字符串
			Reverse(pSecondStart,pSecondEnd);
			//翻转整个字符串
			Reverse(pFirstStart,pSecondEnd);
		}
	}
	
	return pStr;
}

void TestReverseSentence()
{
	//char arr[] = "I am a student."
	//char arr[] = "";//空字符串

	char arr[] = "   ";//空格
	cout<<ReverseSentence(arr)<<endl;
}

void TestLeftRotateString()
{
	char arr[] = "abcdef";
	cout<<LeftRotateString(arr,0)<<endl;//左旋0
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
