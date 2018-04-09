/*�������еĵ�����K�����*/
//1.���������С��k
//2.k = 0 (kΪsize_t���ͣ�������ѭ��)
//3.����ΪNULL 

#include<iostream>
#include<list>
using namespace std;

struct ListNode
{
	int value;
	ListNode* next;
	ListNode(const int& x)
		:value(x)
		,next(NULL)
	{}
};

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
	if(pListHead == NULL || k == 0) //��ֹ����ΪNULL 
	{
		cout<<"����ͷΪNULL��kΪ0 "<<endl;
		return NULL;
	}
	ListNode* pslow = pListHead;
	ListNode* pfast = pListHead;

	for(size_t i=0; i<k-1; i++)//������ǰ��k-1��
	{
		if(pfast == NULL) //��ֹ��������С��K 
		{
			cout<<"���������С��K"<<endl;
			return NULL;
		}
		pfast = pfast->next;
	}

	while(pfast->next != NULL)
	{
		pfast = pfast->next; //����ָ��ͬʱ�� 
		pslow = pslow->next;
	} 
	return pslow;
}

void Test()
{
	ListNode* head1 = new ListNode(8);
	ListNode* head2 = new ListNode(9);
	ListNode* head3 = new ListNode(10);
	ListNode* head4 = new ListNode(5);
	ListNode* head5 = new ListNode(9);
	
	head1->next = head2;
	head2->next = head3;
	head3->next = head4;
	head4->next = head5;

	//���ܲ��ԣ�K�������м䡢ͷ��㡢β��㣩
	cout<<FindKthToTail(head1,2)->value<<endl;
	cout<<FindKthToTail(head1,5)->value<<endl;
	cout<<FindKthToTail(head1,1)->value<<endl;
	//����������ԣ�����ͷNULL����������������K��K����0��
	FindKthToTail(NULL,2);
	FindKthToTail(head1,7);
	FindKthToTail(head1,0);
} 