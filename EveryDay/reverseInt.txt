#include <iostream>
using namespace std;

class Solution2 {
public:
	int reverse(int x) 
	{
		int ret = 0;
		while(x)
		{
			int pop = x%10;
			x = x/10;

			if(ret > INT_MAX/10 || (ret == INT_MAX/10 && pop>7) ||(ret == INT_MAX/10 && pop<-8))
			{
				return 0; 
			}

			ret = 10*ret+pop;
		}

		return ret;
	}
};

void Testreverse()
{
	Solution2 s2;
	cout<<s2.reverse(-123)<<endl;
}

int main()
{
	Testreverse();
	return 0;
}

