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
// 原地反转，时间O(n),空间O(1)
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* r = nullptr;   //初始化空指针当做新链表的尾节点，后面当作pHead的前置节点
        while (pHead)
        {
            ListNode* next = pHead->next;   //标记p的下一节点
            pHead->next = r;                //反转指针
            r = pHead;                      //将p和r向后移一位
            pHead = next;
        }
        return r;        
    }
};

int main(int argc, char const *argv[])
{
	ListNode* a = new ListNode(1);
	ListNode* b = new ListNode(4);
	ListNode* c = new ListNode(10);
    a->next = b;
    b->next = c;

    Solution sol;
    ListNode* res = sol.ReverseList(a);
	while (res)
	{
		cout << res->val << " " ;
		res = res->next;
	}
    cout<<endl;
    return 0;
}