//����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�����������
	//ʹ�õݹ�ķ��������ж����������������������λ�ã�Ȼ�����ж����������������ǲ��Ƕ�����������
	bool VerifySquenceOfBST(vector<int> sequence) {
		return BSTCore(sequence,0,sequence.size()-1);
	}

	bool BSTCore(vector<int> seq, int begin, int end)
	{
		if(seq.empty() || begin > end)
		{
			return false;
		}
		//�������Ľ��С�ڸ��ڵ�
		int i=begin;
		for(; i<end; ++i)
		{
			if(seq[i] > seq[end])
			{
				break;
			}
		}
		//�������Ĵ�����ڵ�
		for(int j=i; j<end; ++j)
		{
			if(seq[j] < seq[end])
			{
				return false;
			}
		}

		//�ж��������ǲ��Ƕ���������
		bool left = true;
		if(i>begin)
		{
			left = BSTCore(seq,begin,i-1);
		}

		//�ж��������ǲ��Ƕ���������
		bool right = true;
		if(i< end -1)
		{
			right = BSTCore(seq,i,end-1);
		}

		return left && right;
	}