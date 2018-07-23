//字符集合 （输入一个字符串，求出该字符串包含的字符集合）

#include<iostream>
using namespace std;
int main()
{
	string s;
	while(cin>>s)
	{
		string res;
		int hashtable[256]={0};
		for(int i=0; i<s.size(); ++i)
		{
			if(hashtable[s[i]] != 1)
			{
				res = res+s[i];
				hashtable[s[i]] = 1;
			}
			
		}
		cout<< res<<endl;
	}
	return 0;
}
