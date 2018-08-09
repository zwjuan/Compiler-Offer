#include <iostream>
using namespace std;

struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) 
		: val(x)
		, next(NULL) 
	{}
};

//add-two-numbers
class Solution1 {
public:
    //思路：将过程分为三种情况，
	/*ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) 
	{
	if(l1 == NULL)
	{
	return l2;
	}

	if(l2 == NULL)
	{
	return l1;
	}

	int brrow = 0;
	ListNode* head = new ListNode(0);
	ListNode* cur = head;
	while(l1 && l2)
	{
	int val = (l1->val+l2->val+brrow)%10;
	brrow = (l1->val+l2->val+brrow)/10;
	cur->next = new ListNode(val);
	l1 = l1->next;
	l2 = l2->next;
	cur = cur->next;
	}

	while(l1 != NULL)
	{
	int val = (l1->val+brrow)%10;
	brrow = (l1->val+brrow)/10;
	cur->next = new ListNode(val);
	l1 = l1->next;
	cur = cur->next;
	}

	while(l2 != NULL)
	{
	int val = (l2->val+brrow)%10;
	brrow = (l2->val+brrow)/10;
	cur->next = new ListNode(val);
	l2 = l2->next;
	cur = cur->next;
	}

	if(brrow != 0)
	{
	cur->next = new ListNode(brrow);
	}

	return head->next;
	}*/
	//思路2：递归解法
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) 
	{
		if(l1 == NULL || l2 == NULL)
		{
			return l1 == NULL ?l2 :l1;
		}

		int value = l1->val+l2->val;
		ListNode* result = new ListNode(value %10);
		result->next = addTwoNumbers(l1->next,l2->next);

		if(value>=10)
		{
			result->next = addTwoNumbers(new ListNode(value/10),result->next);
		}

		return result;
	}

};

void TestList()
{
	ListNode* l11 = new ListNode(2);
	ListNode* l12 = new ListNode(4);
	ListNode* l13 = new ListNode(3);
	l11->next = l12;
	l12->next = l13;

	ListNode* l21 = new ListNode(5);
	ListNode* l22 = new ListNode(6);
	ListNode* l23 = new ListNode(4);
	l21->next = l22;
	l22->next = l23;

	Solution1 s1;
	ListNode* head = s1.addTwoNumbers(l11, l21);

}

int main()
{
	TestList();
	return 0;
}