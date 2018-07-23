#include <iostream>
#include <vector>
#include<string>
#include<set>
using namespace std;

//电话号码
int main()
{
	string s;
	int length;//输入的电话号码个数
	string NUM = "222333444555666777788889999";
	while(cin >> length)
	{
		set<string> data;
		int cnt;
		for(int i=0; i<length; ++i)
		{
			cnt = 0;
			string res;
			cin >> s;
			for(int j=0; j<s.length(); ++j)
			{
				if(s[j] >= 'A' && s[j] <= 'Z')
				{
					res += NUM[s[j]-'A'];
					cnt++;
					if(cnt == 3)
					{
						res += "-";
					}
				}
				else if(s[j] >= '0' && s[j] <= '9')
				{
					res += s[j];
					cnt++;
					if(cnt == 3)
					{
						res += "-";
					}
				}
			}
			data.insert(res);
		}

		for(set<string>::iterator it = data.begin(); it != data.end(); it++)
		{
			cout<<*it<<endl;
		}
		cout<<endl;
	}

	return 0;

}