#include <iostream>
#include <vector>
using namespace std;

// 递归,时间复杂度O(2^n)
int Fib1(int number){
    if (number <= 0)
        return 0;
    if (number <= 1) 
        return 1;
    else 
        return Fib1(number-1)+Fib1(number-2);
}

// 普通递归存在很多重复计算，为了避免重复运算，构造数组把计算过的保存下来
// 时间复杂度O(n),空间复杂度O(n)
int dp2[10000];
int Fib2(int number){
    if(dp2[number])
        return dp2[number];
    if (number <= 0)
        return 0;
    if (number <= 1) 
        return 1;
    else 
        return dp2[number] = Fib1(number-1)+Fib1(number-2);
}

// 动态规划，优化递归栈空间（迭代） 注意这里下标和前面不一样，第一位多一个0
// 时间复杂度O(n),空间复杂度O(n)
int Fib3(int number){
    if (number <= 0)
        return 0;
    vector<int> dp(number+1,0);
    dp[1] = 1;
    // cout << dp[0];
    for (int i = 2; i <= number; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[number];
}

// 优化动态规划
// 每次就用到了最近的两个数，所以我们可以只存储最近的两个数而不是存储整个数列、
// 时间复杂度O(n),空间复杂度O(1)
int Fib4(int number){
    if (number <= 0)
        return 0;
    int a = 1, b = 0;
    for (int i = 1; i <= number; i++)
    {
        a = a+b;         //实现a每次=a+b
        b = a-b;         //b=上一个a
    }
    return b;            //第一次循环b从第一个1开始，所以返回b
}

// 测试
int main(int argc, char const *argv[])
{
    for (int i = 1; i <= 10; i++)
    {
        cout << Fib1(i) << " ";
        cout << Fib2(i) << " ";
        cout << Fib3(i) << " ";
        cout << Fib4(i) << " " << endl;
    }
    return 0;
}
