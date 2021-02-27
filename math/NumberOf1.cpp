#include <iostream>
#include <vector>
using namespace std;

// 输入一个整数，输出该数32位二进制表示中1的个数。其中负数用补码表示
// 11000100   11000100-1=11000011   11000100 & (11000100-1) = 11000100 & 11000011 = 11000000
// 即n&(n-1)一次可以消掉二进制中的最后一个1
int  NumberOf1_2(int n) {
     int result = 0;
     while (n != 0)
     {
          result++;
          n &= (n-1);
     }
     return result;
}

// 将1从第1位到32位分别与n相&，等于1则n的2进制那一位是1
int  NumberOf1_1(int n) {
     int result = 0;
     int mark = 0x01;
     while (mark != 0)
     {
          if (mark & n)  ++result;
          mark <<= 1;
          // cout << mark <<endl;
     }
     return result;
}

int main(int argc, char const *argv[])
{
     cout << NumberOf1_1(10) << endl;
     cout << NumberOf1_2(10) << endl;
     return 0;
}
