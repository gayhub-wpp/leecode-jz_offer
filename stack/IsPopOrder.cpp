#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
// 第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int len = popV.size();
        if (len == 0)
        {
            return false;
        }

        stack<int> vec;       //辅助栈
        int i = 0, j = 0;     //用指针i指向pushV的第一个位置， 指针j指向popV的第一个位置
        while(i<len){
            if (pushV[i] == popV[j]){     //pushV[i]==popV[j], 说明这个元素是放入栈中立马弹出，所以，++i, ++j，
                i++,j++;
                while (!vec.empty() && vec.top() == popV[j])   //然后应该检查popV[j]与栈顶元素是否相等，如果相等，++j, 并且弹出栈顶元素
                {
                    {
                        j++;
                        vec.pop();
                    }
                }
            }
            else{                //pushV[i] != popV[j]， 那么应该将pushV[i]放入栈中， ++i
                vec.push(pushV[i]);
                i++;
            }
        }
        return vec.empty();        //栈是否为空，如果为空，说明匹配，否则不匹配。
    }
};

int main(int argc, char const *argv[])
{
    Solution solu;
    vector<int> vec1{1,2,3,4,5};
    vector<int> vec2{4,5,3,2,1};

    cout << solu.IsPopOrder(vec1, vec2) << endl;
    return 0;
}



