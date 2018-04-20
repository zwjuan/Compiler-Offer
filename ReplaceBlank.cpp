//��ԭ�����ַ������滻
//1.��ǰ�������滻��ʱ�临�Ӷ�ΪO(N^2)��
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

//2.�Ӻ���ǰ���滻���ȱ���һ��ͳ�ƿ��ַ��ĸ����������δӺ�ʼ�滻�ַ�
void ReplaceBlank(char String[],int length)//lengthΪԭ����ĳ���
{
	if(String == NULL || length == 0)
	{
		return ;
	}

	int originalLength = 0;
	int numberOfBlank = 0;
	int i = 0;
	//��һ�α���ͳ��ԭ�ַ����ĳ����Լ����ַ��ĸ���
	while(String[i] != '\0')
	{
		if(String[i] == ' ')
		{
			numberOfBlank++;
		}
		originalLength++;

		i++;
	}

	//newLengthΪ�ѿո��滻Ϊ��%20�����ַ����ĳ���
	int newLength = originalLength + numberOfBlank*2;
	if(newLength > length)//�滻����ַ����ȴ���ԭ�ַ��ĳ���
	{
		return ;
	}

	//��ǰ��������滻
	int indexOfOriginal = originalLength;
	int indexNew = newLength;

	while(indexOfOriginal >= 0 && indexNew > indexOfOriginal)//��Ҫ��֤indexNew>indexOfOriginal
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
	//��������
	//1.������ַ��������ո�
	char s1[40] = "  we are   happy  ";
	ReplaceBlank(s1,40);
	cout<<s1<<endl;
	
	//2.������ַ���û�пո�
	char s2[20] = "wearehappy";
	ReplaceBlank(s2,20);
	cout<<s2<<endl;

	//3.��������
	ReplaceBlank(NULL,10);//�ַ����Ǹ�NULLָ��

	char s3[10] = ""; //�ַ����Ǹ����ַ���
	ReplaceBlank(s3,10);
	cout<<s3<<endl;

	char s4[10] = "  "; //�ַ���ֻ��һ���ո��ַ�
	ReplaceBlank(s4,10);
	cout<<s4<<endl;
}