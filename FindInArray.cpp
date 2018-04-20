/*二维数组中的查找
有一个二维数组，数组的每行从左到右是递增的，每列从上到下是递增的，在这样的数组中查找一个数字是否存在。
时间复杂度小于O(N)
*/

#include<iostream>
using namespace std;

 bool FindInArray(int* arr,int rows,int columns,int number)
 {
	 if(arr != NULL && rows > 0 && columns > 0)  //对参数进行检测
	 { 
		 size_t row = 0;
		 size_t col = columns -1;
		 while( row<rows && col>=0)
		 {
			 if(arr[row*columns+col] < number)
			 {
				 row++;
			 }
			 else if(arr[row*columns+col] > number)
			 {
				 col--;
			 }
			 else //arr[i*columns+j] == number
			 {
				 return true;
			 }
		 }
	 }
	 return false;
 }

 void TestFindInArray()
 {
	 int arr[] = {1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};
	 //测试用例
	  cout<<FindInArray(arr,4,4,9)<<endl;//二维数组包含查找的数字
	  cout<<FindInArray(arr,4,4,5)<<endl; //二维数组没有查找的数字
	  cout<<FindInArray(NULL,4,4,5)<<endl; //特殊测试（输入空指针）
 }