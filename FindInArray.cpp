/*��ά�����еĲ���
��һ����ά���飬�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ����ģ��������������в���һ�������Ƿ���ڡ�
ʱ�临�Ӷ�С��O(N)
*/

#include<iostream>
using namespace std;

 bool FindInArray(int* arr,int rows,int columns,int number)
 {
	 if(arr != NULL && rows > 0 && columns > 0)  //�Բ������м��
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
	 //��������
	  cout<<FindInArray(arr,4,4,9)<<endl;//��ά����������ҵ�����
	  cout<<FindInArray(arr,4,4,5)<<endl; //��ά����û�в��ҵ�����
	  cout<<FindInArray(NULL,4,4,5)<<endl; //������ԣ������ָ�룩
 }