/*求链表中的倒数第K个结点*/
//1.链表的总数小于k
//2.k = 0 (k为size_t类型，导致死循环)
//3.链表为NULL 

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
	if(pListHead == NULL || k == 0) //防止链表为NULL 
	{
		cout<<"链表头为NULL或k为0 "<<endl;
		return NULL;
	}
	ListNode* pslow = pListHead;
	ListNode* pfast = pListHead;

	for(size_t i=0; i<k-1; i++)//快结点向前走k-1步
	{
		if(pfast == NULL) //防止链表总数小于K 
		{
			cout<<"链表的总数小于K"<<endl;
			return NULL;
		}
		pfast = pfast->next;
	}

	while(pfast->next != NULL)
	{
		pfast = pfast->next; //两个指针同时走 
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

	//功能测试（K在链表中间、头结点、尾结点）
	cout<<FindKthToTail(head1,2)->value<<endl;
	cout<<FindKthToTail(head1,5)->value<<endl;
	cout<<FindKthToTail(head1,1)->value<<endl;
	//特殊输入测试（链表头NULL，链表结点总数少于K，K等于0）
	FindKthToTail(NULL,2);
	FindKthToTail(head1,7);
	FindKthToTail(head1,0);
} 