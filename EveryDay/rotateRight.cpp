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
	//˼·1�������δ����ҵ�newhead��㣬Ȼ��ǰ�ߵ��������ӵ����������
	//˼·2������ѭ������
	ListNode *rotateRight(ListNode *head, int k) {
		if(head == NULL || k<=0) //�п�
		{
			return head;
		}

		int len = 1;
		ListNode* cur = head;
		//��������õ�����ĳ���
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