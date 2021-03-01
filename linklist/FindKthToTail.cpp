#include <iostream>
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 输入一个链表，输出该链表中倒数第k个结点。
// 快慢指针
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        int i = k;
        ListNode* first = pHead;
        ListNode* second = pHead;
        while (i--)
        {
            if (second == nullptr)  //链表长度不足k，返回空
            {
                return second;
            }
            second = second->next;
        }
        while (second != nullptr)
        {
            second = second->next;
            first = first->next;
        }
        return first;
    }
};

int main(int argc, char const *argv[])
{
    ListNode a = ListNode(1);
    ListNode b = ListNode(4);
    ListNode c = ListNode(10);
    a.next = &b;
    b.next = &c;
    Solution sol;
    ListNode* res = sol.FindKthToTail(&a, 3);
    cout << res->val << endl;
    return 0;
}
