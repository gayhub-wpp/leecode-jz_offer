#include <vector>
#include <iostream>
#include <math.h>
using namespace std;
// 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

// f(n)=f(n-1)+f(n-2)+...+f(1)
// f(n-1)=f(n-2)+...f(1)
// 得:f(n)=2*f(n-1)
int jumpFloorII(int number) {
    return pow(2,number-1);
}

//f(n) = f(n-1)+……+f(1)+1
int jumpFloorI(int number) {
    vector<int> dp(number + 1 , 0);   //f()
    dp[1] = 1;
    int sum = 1; //sum = f(n-1)+……+f(1)
    for (int i = 2; i <= number; i++)
    {
        dp[i] = sum + 1 ;    //dp[i]=f(n-1)+……+f(1)+1
        sum += dp[i];        //sum = f(n-1)+……+f(1)
    }
    return dp[number];
}

int main(int argc, char const *argv[])
{
    for (int i = 1; i <= 10; i++)
    {
        cout << jumpFloorI(i) << " ";
    }
    return 0;
}
