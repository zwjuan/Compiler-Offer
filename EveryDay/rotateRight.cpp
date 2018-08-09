#include <iostream>
using namespace std;

//rotate-list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution1 {
public:
	//思路1：发生段错误（找到newhead结点，然后将前边的链表链接到后面的链表）
	//思路2：借助循环链表
	ListNode *rotateRight(ListNode *head, int k) {
		if(head == NULL || k<=0) //判空
		{
			return head;
		}

		int len = 1;
		ListNode* cur = head;
		//遍历链表得到链表的长度
		while(cur->next)
		{
			++len;
			cur = cur->next;
		}

		cur->next = head;
		k =len - k%len;

		for(int i=0; i<k; ++i)
		{
			cur = cur->next;
		}

		head = cur->next;
		cur->next = NULL;

		return head;
	}
};

void Testrotate()
{
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(2);
	//ListNode* l3 = new ListNode(3);
	//ListNode* l4 = new ListNode(4);
	//ListNode* l5 = new ListNode(5);
	l1->next = l2;
	//l2->next = l3;
	/*l3->next = l4;
	l4->next = l5;*/
	Solution1 s;
	ListNode *head = s.rotateRight(l1,3);
}

int main()
{
	Testrotate();
	return 0;
}