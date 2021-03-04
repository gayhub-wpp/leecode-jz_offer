#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
// 定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
class Solution {
public:
    stack<int> s, smin;  //辅助栈，
    void push(int value) {
        s.push(value);
        if (smin.empty())
        {
            smin.push(value);
        }
        else{
            if (value<smin.top())   //只有比当前栈顶小才进栈，所以栈顶就是最小min
            {
                smin.push(value);
            }
        }
    }
    void pop() {
        if (s.top() == smin.top())
        {
            smin.pop();
        }
        s.pop();
    }
    int top() {
        return s.top();        
    }
    int min() {
        return smin.top();
    }
};


int main(int argc, char const *argv[])
{
    stack<int> s1;
    stack<int> s2;

    
    Solution solu;
    solu.s = s1;
    solu.smin = s2;
    solu.push(10);
    solu.push(3);
    solu.push(5);
    solu.push(2);
    solu.push(4);
    solu.push(8);
    cout << solu.min();
    return 0;
}
