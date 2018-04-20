//在原来的字符上做替换
//1.从前往后做替换（时间复杂度为O(N^2)）
void ReplaceBlankF(char String[],int length)
{
	if(String == NULL || length == 0)
	{
		return ;
	}

	size_t index = 0;
	while(String[index] != '\0')
	{
		if(String[index] != ' ')
		{
			index++;
		}
		else
		{
			size_t end = index;
			while(String[end] != '\0')
			{
				end++;
			}

			size_t newEnd = end+2;
			if(newEnd > length)
			{
				return;
			}

			while(end > index && newEnd > end )
			{
				String[newEnd--] = String[end--];
			}

			String[index++] = '%';
			String[index++] = '2';
			String[index++] = '0';

		}
	}
}

//2.从后往前做替换，先遍历一遍统计空字符的个数，再依次从后开始替换字符
void ReplaceBlank(char String[],int length)//length为原数组的长度
{
	if(String == NULL || length == 0)
	{
		return ;
	}

	int originalLength = 0;
	int numberOfBlank = 0;
	int i = 0;
	//第一次遍历统计原字符串的长度以及空字符的个数
	while(String[i] != '\0')
	{
		if(String[i] == ' ')
		{
			numberOfBlank++;
		}
		originalLength++;

		i++;
	}

	//newLength为把空格替换为‘%20’后字符串的长度
	int newLength = originalLength + numberOfBlank*2;
	if(newLength > length)//替换后的字符长度大于原字符的长度
	{
		return ;
	}

	//从前往后进行替换
	int indexOfOriginal = originalLength;
	int indexNew = newLength;

	while(indexOfOriginal >= 0 && indexNew > indexOfOriginal)//需要保证indexNew>indexOfOriginal
	{
		if(String[indexOfOriginal] != ' ')
		{
			String[indexNew] = String[indexOfOriginal];
			indexNew--;
			indexOfOriginal--;
		}
		else
		{
			String[indexNew--] = '0';
			String[indexNew--] = '2';
			String[indexNew--] = '%';
			indexOfOriginal --;
		}
	}
	
}

void TestReplaceBlank()
{
	//测试用例
	//1.输入的字符串包含空格
	char s1[40] = "  we are   happy  ";
	ReplaceBlank(s1,40);
	cout<<s1<<endl;
	
	//2.输入的字符串没有空格
	char s2[20] = "wearehappy";
	ReplaceBlank(s2,20);
	cout<<s2<<endl;

	//3.特殊输入
	ReplaceBlank(NULL,10);//字符串是个NULL指针

	char s3[10] = ""; //字符串是个空字符串
	ReplaceBlank(s3,10);
	cout<<s3<<endl;

	char s4[10] = "  "; //字符串只有一个空格字符
	ReplaceBlank(s4,10);
	cout<<s4<<endl;
}