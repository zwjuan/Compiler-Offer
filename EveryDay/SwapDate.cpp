#include <iostream>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//1. swap-nodes-in-pairs(成对交换节点)
class Solution1 {
public:
	ListNode *swapPairs(ListNode *head) 
	{
		ListNode* phead = new ListNode(0);
		phead->next= head;
		ListNode* pre = phead;
		ListNode* cur = head;

		//空节点或一个节点的话直接返回
		while( cur!= NULL && cur->next != NULL)
		{
			ListNode* next = cur->next->next;
			cur->next->next = cur;
			pre->next = cur->next;
			if(next != NULL && next->next!= NULL)
			{
				cur->next = next->next;
			}
			else
			{
				cur->next = next;
			}

			pre = cur;
			cur = next;
		}

		return phead->next;
	}
};

void TestswapPairs()
{
	Solution1 s;
	ListNode l1(1);
	ListNode l2(2);
	ListNode l3(3);
	ListNode l4(4);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;

	ListNode* head = s.swapPairs(&l1);
}

int main()
{
	TestswapPairs();
	return 0;
}