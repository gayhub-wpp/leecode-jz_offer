#include <iostream>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
// 新建一个表头，比较两个链表的第一个元素，把较小的插到新链表最后一位
    ListNode* Merge1(ListNode* pHead1, ListNode* pHead2) {
		if (pHead1 == nullptr && pHead2 == nullptr)
			return nullptr;
        if (pHead1 == nullptr)
			return pHead2;
		if (pHead2 == nullptr)
			return pHead1;
		ListNode* head = new ListNode(0);    //表头head
		ListNode* p = head;     //尾指针，用以插入别的节点在其之后
		while (pHead1 != nullptr && pHead2 != nullptr)
		{
			if (pHead1->val <= pHead2->val)
			{
				p->next = pHead1;
				pHead1 = pHead1->next;
			}
			else{
				p->next = pHead2;
				pHead2 = pHead2->next;
			}
			p = p->next;		
		}
		p->next = pHead1 ? pHead1 : pHead2;
		return head->next;  //返回head->next为真实的链表第一个节点，head为0
    }

// 递归
    ListNode* Merge2(ListNode* pHead1, ListNode* pHead2) {
		if (pHead1 == nullptr && pHead2 == nullptr)
			return nullptr;
        if (pHead1 == nullptr)
			return pHead2;
		if (pHead2 == nullptr)
			return pHead1;
		if (pHead1->val <= pHead2->val)
		{
			pHead1->next = Merge2(pHead1->next, pHead2);
			return pHead1;
		}
		else {
        	pHead2->next = Merge2(pHead1, pHead2->next);
        	return pHead2;
     	}
	}
	
};

int main(int argc, char const *argv[])
{
	ListNode* a = new ListNode(1);
	ListNode* b = new ListNode(4);
	ListNode* c = new ListNode(10);
    a->next = b;
    b->next = c;

	ListNode* d = new ListNode(2);
	ListNode* e = new ListNode(3);
	ListNode* f = new ListNode(8);
    d->next = e;
    e->next = f;

    Solution sol;
    ListNode* res = sol.Merge2(a, d);
	while (res)
	{
		cout << res->val << " " ;
		res = res->next;
	}
	
    return 0;
}