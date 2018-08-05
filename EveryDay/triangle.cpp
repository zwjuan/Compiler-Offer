#include<iostream>
#include<vector>
using namespace std;

//triangle
//思路：使用动态规划，从下往上，每一行的结果根据下面一行的路基累计和而计算

class Solution1 {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		for(int i=triangle.size()-2; i>=0; --i)
		{
			for(int j=0; j<i+1; j++)
			{
				if(triangle[i+1][j] > triangle[i+1][j+1])
				{
					triangle[i][j] += triangle[i+1][j+1];
				}
				else
				{
					triangle[i][j] += triangle[i+1][j];
				}
			}
		}

		return triangle[0][0];
	}
};

int main()
{
	vector<vector<int> > triangle;
	triangle.resize(4);

	triangle[0].push_back(2);
	triangle[1].push_back(3);
	triangle[1].push_back(4);
	triangle[2].push_back(6);
	triangle[2].push_back(5);
	triangle[2].push_back(7);
	triangle[3].push_back(4);
	triangle[3].push_back(1);
	triangle[3].push_back(8);
	triangle[3].push_back(3);

	Solution1 s1;
	cout<<s1.minimumTotal(triangle)<<endl;

	return 0;
}