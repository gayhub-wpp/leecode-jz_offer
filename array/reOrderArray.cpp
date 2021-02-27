#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
// 使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，
// 并保证奇数和奇数，偶数和偶数之间的相对位置不变。

// 创建一个vector，遍历原array，将偶数放入vector，并在原array删除，最后将vector中所有数加到原array末尾
vector<int> reOrderArray1(vector<int>& array) {
    int len = array.size();
    vector<int> vec;
    for (vector<int>::iterator i = array.begin(); i != array.end();)
    {
        int tmp = *i;
        if (tmp & 1)
        {
            i++;
            continue;
        }
        else{
            vec.push_back(tmp);
            array.erase(i);
        }
    }

    for (vector<int>::iterator i2=vec.begin(); i2 != vec.end(); i2++)
    {
        array.push_back(*i2);
    }
    return array;
}

// 先遍历一遍,统计偶数的个数cnt，第二遍遍历将奇数从0开始放，偶数从cnt开始放
vector<int> reOrderArray2(vector<int>& array) {
    int len = array.size();
    int cnt = 0;
    for(int i = 0; i< len; i++){
        if(array[i]&1)  cnt++;
    }
    vector<int> vec(len);
    for (int j = 0,k = 0; j < len; j++)
    {
        array[j]&1 ? vec[k++]=array[j] : vec[cnt++]=array[j];
    }
    return vec;
}


int main(int argc, char const *argv[])
{
    vector<int> v = {1,2,3,4,5,6};
    vector<int> v1 = reOrderArray2(v);
    for (int  i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " " ;
    }
    cout << endl;
    return 0;
}
