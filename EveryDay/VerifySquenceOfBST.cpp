//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。
	//使用递归的方法，先判断数组的左子树和右子树的位置，然后在判断左子树、右子树是不是二叉搜索树。
	bool VerifySquenceOfBST(vector<int> sequence) {
		return BSTCore(sequence,0,sequence.size()-1);
	}

	bool BSTCore(vector<int> seq, int begin, int end)
	{
		if(seq.empty() || begin > end)
		{
			return false;
		}
		//左子树的结点小于根节点
		int i=begin;
		for(; i<end; ++i)
		{
			if(seq[i] > seq[end])
			{
				break;
			}
		}
		//右子树的大与根节点
		for(int j=i; j<end; ++j)
		{
			if(seq[j] < seq[end])
			{
				return false;
			}
		}

		//判断左子树是不是二叉搜索树
		bool left = true;
		if(i>begin)
		{
			left = BSTCore(seq,begin,i-1);
		}

		//判断右子树是不是二叉搜索树
		bool right = true;
		if(i< end -1)
		{
			right = BSTCore(seq,i,end-1);
		}

		return left && right;
	}